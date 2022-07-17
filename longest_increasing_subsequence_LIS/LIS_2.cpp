#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// https://cses.fi/problemset/task/1145
// https://oj.vnoi.info/problem/lis

void dp_with_binary_search(const vector<int> &arr) {
    int n = arr.size();
    vector<int> dp, trace(n, -1), index;

    dp.push_back(arr[0]);
    index.push_back(0);

    int lis = 1, end_index = -1;

    for (int i = 1; i < n; ++i) {
        int j = int(lower_bound(begin(dp), end(dp), arr[i]) - begin(dp));
        if (j == (int) dp.size()) {
            dp.push_back(arr[i]);
            trace[i] = index.back();
            index.push_back(i);
        }
        else {
            dp[j] = arr[i];
            index[j] = i;
            if (j > 0) {
                trace[i] = index[j - 1];
            }
        }

        if (lis < j + 1) {
            lis = j + 1;
            end_index = i;
        }
    }

    vector<int> ans;
    while (end_index != -1) {
        ans.push_back(arr[end_index]);
        end_index = trace[end_index];
    }

    assert(lis == (int) ans.size());
    reverse(begin(ans), end(ans));

    cout << lis << '\n';
    // for (int i = 0; i < lis; ++i) {
    //     if (i > 0) cout << ' ';
    //     cout << ans[i];
    // }
    // cout << '\n';
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

    dp_with_binary_search(arr);

    return 0;
}