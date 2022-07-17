// https://www.spoj.com/problems/PRIME1/cstart=10

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long ceil_div(long long a, long long b) {
    return a / b + ((a ^ b) > 0 && (a % b != 0));
    // floor(x) <= x <= ceil(x) for both positive and negative
}

long long floor_div(long long a, long long b) {
    return a / b - ((a ^ b) < 0 && (a % b != 0));
}

vector<bool> primes;
void segment_sieve(long long L, long long R) {
    int n = R - L + 1;
    primes.assign(n, true);
    for (long long i = 2, _sqrt = sqrt(R); i <= _sqrt; ++i) {
        long long start = max(i * i, ceil_div(L, i) * i);
        for (long long j = start; j <= R; j += i) {
            primes[j - L] = false;
        }
    }

    if (L == 1) primes[1 - L] = false;
    for (long long i = L; i <= R; ++i) {
        if (primes[i - L]) {
            cout << i << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    long long a, b;
    cin >> a >> b;
    segment_sieve(a, b);

    // input: 1000000000000 1000000100000
    // output should be: 3614
    return 0;
}