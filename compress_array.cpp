#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

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

    vector<pair<int, int>> b;
    b.reserve(n);
    for (int i = 0; i < n; ++i) {
        b.emplace_back(arr[i], i);
    }
    sort(begin(b), end(b));

    vector<int> rank(n);
    int current_rank = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && b[i].first > b[i - 1].first) {
            current_rank++;
        }
        rank[b[i].second] = current_rank;
    }

    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << ' ';
        cout << rank[i];
    }
    cout << '\n';

    return 0;
}