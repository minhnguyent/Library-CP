#include <iostream>

using namespace std;

long long ceil_div(long long a, long long b) {
    return a / b + ((a ^ b) > 0 && (a % b != 0));
    // floor(x) <= x <= ceil(x) for both positive and negative
}

long long floor_div(long long a, long long b) {
    return a / b - ((a ^ b) < 0 && (a % b != 0));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    long long a, b;
    cin >> a >> b;
    cout << ceil_div(a, b) << ' ' << floor_div(a, b) << '\n';

    return 0;
}