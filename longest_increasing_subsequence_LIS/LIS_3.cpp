#include <bits/stdc++.h>

using namespace std;

struct MaxFenwickTree {
    int n;
    vector<int> tree;

    MaxFenwickTree() {}

    MaxFenwickTree(int n) {
        this -> n = n;
        tree.resize(n + 1);
    }

    void modify(int index, int v) {
        for (int i = index; i <= n; i += (i & -i)) {
            tree[i] = max(tree[i], v);
        }
    }

    int pref_max(int index) {
        int maxv = 0;
        for (int i = index; i > 0; i -= (i & -i)) {
            maxv = max(maxv, tree[i]);
        }
        return maxv;
    }


};

void use_fenwick_tree(const vector<int> &arr) {
    int n = arr.size();

    // Compress array
    vector<pair<int, int>> b;
    b.reserve(n);
    for (int i = 0; i < n; ++i ) {
        b.emplace_back(arr[i], i);
    }

    sort(begin(b), end(b));
    int curr_rank = 1;
    vector<int> rank(n);
    for (int i = 0; i < n; ++i) {
        if (i > 0 && b[i].first > b[i - 1].first) {
            curr_rank++;
        }
        rank[b[i].second] = curr_rank;
    }

    MaxFenwickTree tree(n);

    int lis = 1;

    for (int i = 0; i < n; ++i) {
        int curr = tree.pref_max(rank[i] - 1) + 1;
        lis = max(lis, curr);
        tree.modify(rank[i], curr); 
    }
    cout << lis << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int t = 0; t < n; ++t) {
        cin >> arr[t];
    }

    use_fenwick_tree(arr);        

    return 0;
}