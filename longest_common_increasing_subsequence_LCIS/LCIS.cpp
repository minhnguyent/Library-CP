// Codeforces: https://codeforces.com/contest/10/problem/D

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// change max-min
template<typename T, typename G> bool chmax(T &a, const G &b) { return (a < b ? a = b, true : false); }
template<typename T, typename G> bool chmin(T &a, const G &b) { return (a > b ? a = b, true : false); }

void LCIS(const vector<int> &A, const vector<int> &B) {
    int n = (int) A.size(), m = (int) B.size();
    vector<int> dp(m), trace(m, -1);
    for (int i = 0; i < n; ++i) {
        int curr_length = 0;
        int prev_index = -1;
        for (int j = 0; j < m; ++j) {
            if (A[i] == B[j]) {
                if (chmax(dp[j], curr_length + 1)) {
                    // dp[j] = max(dp[j], curr_length + 1);
                    trace[j] = prev_index;
                }
            }
            else if (A[i] > B[j]) {
                if (chmax(curr_length, dp[j])) {
                    // curr_length = max(curr_length, dp[j]);
                    prev_index = j;
                }
            }
        }
    }
    int length_of_lcis = 0;
    int index = -1;
    for (int i = 0; i < m; ++i) {
        if (chmax(length_of_lcis, dp[i])) {
            index = i;
        }
    }
    cout << length_of_lcis << '\n';
    if (length_of_lcis) {
        vector<int> ans;
        while (index != -1) {
            ans.push_back(B[index]);
            index = trace[index];
        }
        reverse(begin(ans), end(ans));
        assert(length_of_lcis == (int) ans.size());
        for (int i = 0; i < length_of_lcis; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

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