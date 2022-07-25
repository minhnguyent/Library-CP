// Codeforces: https://codeforces.com/contest/10/problem/D

#include <iostream>
#include <vector>
#include <cassert>
#include <array>

using namespace std;

template<typename T, typename G> bool chmax(T &a, const G &b) { return (a < b ? a = b, true : false); }
template<typename T, typename G> bool chmin(T &a, const G &b) { return (a > b ? a = b, true : false); }

void LCIS(const vector<int> &A, const vector<int> &B) {
    int n = (int) A.size(), m = (int) B.size();
    vector<array<int, 3>> c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i] == B[j]) {
                c.push_back({i, j, A[i]});
            }
        }
    }

    sort(begin(c), end(c));
    // Now, finding LIS on C 
    int sz = (int) c.size();
    vector<int> dp(sz, 1), trace(sz, - 1);
    int lis = 0; 
    int index = -1;
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < i; ++j) {
            if (c[j][1] < c[i][1] && c[j][2] < c[i][2]) {
                if (chmax(dp[i], 1 + dp[j])) {
                    trace[i] = j;
                }
            }
        }
        if (chmax(lis, dp[i])) {
            index = i;
        }
    }
    cout << lis << '\n';
    if (lis) {
        vector<int> ans;
        while (index != -1) {
            ans.push_back(c[index][2]);
            index = trace[index];
        }
        assert(lis == (int) ans.size());
        reverse(begin(ans), end(ans));
        for (int i = 0; i < lis; ++i) {
            if (i > 0) cout << ' ';
            cout << ans[i];
        }
    }

    // Time complexity: O(N * M)
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }
    LCIS(A, B);

    // Longest common increasing subsequence
    return 0;
}