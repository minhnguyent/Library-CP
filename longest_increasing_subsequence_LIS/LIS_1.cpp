#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// https://cses.fi/problemset/task/1145
// https://oj.vnoi.info/problem/lis

void brute_force(const vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, 1), trace(n, -1);
    // dp[i] = length of the longest strictly increasing subsequence end at index i
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                if (dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    trace[i] = j;
                }
            }
        }
    }

    int lis = 1, end_index = -1;
    for (int i = 0; i < n; ++i) {
        if (lis < dp[i]) {
            lis = dp[i];
            end_index = i;
        }
    }

    vector<int> ans;
    while (end_index != -1) {
        ans.push_back(arr[end_index]);
        end_index = trace[end_index];
    }

    assert(ans.size() == lis);
    reverse(begin(ans), end(ans));

    cout << lis << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        if (i > 0) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
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

    brute_force(arr);

    return 0;
}