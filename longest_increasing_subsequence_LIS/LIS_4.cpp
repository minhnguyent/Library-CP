#include <bits/stdc++.h>

using namespace std;

struct MaxSegmentTree {
    int n;
    vector<int> tree;

    MaxSegmentTree() {}

    MaxSegmentTree(int n) {
        this -> n = n;
        tree.resize(2 * n);
    }

    void modify(int index, int v) {
        tree[index + n] = v;
        for (int i = (index + n) / 2; i > 0; i /= 2) {
            tree[i] = max(tree[i], v);
        }
    }

    int max_query(int l, int r) {
        // return min value in range [l..r)
        int maxv = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) maxv = max(maxv, tree[l++]);
            if (r & 1) maxv = max(maxv, tree[--r]);
        }
        return maxv;
    }


};

void use_segment_tree(const vector<int> &arr) {
    int n = arr.size();

    // Compress array
    vector<pair<int, int>> b;
    b.reserve(n);
    for (int i = 0; i < n; ++i ) {
        b.emplace_back(arr[i], i);
    }

    sort(begin(b), end(b));
    int curr_rank = 0;
    vector<int> rank(n);
    for (int i = 0; i < n; ++i) {
        if (i > 0 && b[i].first > b[i - 1].first) {
            curr_rank++;
        }
        rank[b[i].second] = curr_rank;
    }

    MaxSegmentTree tree(n);

    int lis = 1;

    for (int i = 0; i < n; ++i) {
        int curr = tree.max_query(0, rank[i]) + 1;
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

    use_segment_tree(arr);        

    return 0;
}