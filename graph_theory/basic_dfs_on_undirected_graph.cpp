#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = (int) 1e5 + 3;
vector<int> g[N]; // adjacency list, undirected graph 
int num[N], low[N], finish[N];
int dfs_timer;

void dfs(int u) {
    low[u] = num[u] = ++dfs_timer;
    for (int &v : g[u]) {
        if (num[v] != 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else {
            low[u] = min(low[u], num[v]);
        }
    }
    finish[u] = dfs_timer;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (num[i] == 0) {
            dfs(i);
        }
    }

    // Time complexity: O(|V| + 2|E|)
    return 0;
}