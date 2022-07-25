#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;

const int N = (int) 1e5 + 3;
vector<int> g[N]; // adjacency list, undirected graph 
bool visited[N];
int par[N]; // parrent of vertex u
int dist[N]; // minimum distance from root to u

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int &v : g[u]) {
            if (visited[v] == false) {
                visited[v] = true;
                par[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
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

    for (int i = 1; i <= n; ++i) dist[i] = INF;

    bfs(1);
    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        cout << (dist[i] == INF ? -1 : dist[i]);
    }
    cout << '\n';

    // Time complexity: O(|V| + 2|E|)
    return 0;
}