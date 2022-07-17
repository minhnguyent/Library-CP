#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct Node {
    
};

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree() {
        n = 0;
    }

    SegmentTree(int n) {
        init(n);
    }

    void init(int sz) {
        n = 1;
        while (n < sz) n *= 2;
        tree.assign(2 * n, 0);
    }

    int merge(const int &left, const int &right) {
        return left + right;
    }

    void process_update(int node, int left, int right, int i, int v) {
        if (left == right) {
            assert(left == i);
            tree[node] = v;
            return;
        }
        int mid = left + (right - left) / 2;
        if (i <= mid) {
            process_update(node * 2, left, mid, i, v);
        }
        else {
            process_update(node * 2 + 1, mid + 1, right, i, v);
        }
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    int process_get_sum(int node, int left, int right, int u, int v) {
        if (left > v || right < u) return 0;
        if (u <= left && right <= v) {
            return tree[node];
        }
        int mid = left + (right - left) / 2;
        int left_ans = process_get_sum(node * 2, left, mid, u, v);
        int right_ans = process_get_sum(node * 2 + 1, mid + 1, right, u, v);
        return merge(left_ans, right_ans);
    }

    // ___________________________ main methods start here  ___________________________

    void build(const vector<int> &initial) {
        int sz = (int) initial.size();
        if (n == 0) init(sz);
        for (int i = 0; i < sz; ++i) {
            tree[i + n] = initial[i];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    void update(int i, int v) {
        process_update(1, 1, n, i, v);
    }

    int get_sum(int u, int v) {
        return process_get_sum(1, 1, n, u, v);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    SegmentTree tree;
    tree.build(arr);

    int q;
    cin >> q;
    // 0 i v: set arr[i] = v
    // 1 u v: return sum of all elements in range [u, v]
    // (1-indexed)
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 0) {
            int i, v;
            cin >> i >> v;
            tree.update(i, v);
        }
        else {
            int u, v;
            cin >> u >> v;
            cout << tree.get_sum(u, v) << '\n';
        }
    }

    return 0;
}