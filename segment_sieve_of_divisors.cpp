#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int N = (int) 1e6; // R - L + 1 <= N
int divisors[N + 3];

void segment_sieve(long long L, long long R) {
    for (int i = 1, _sqrt = sqrt(R); i <= _sqrt; i++) {
        long long start1 = (L + i - 1) / i * i;
        long long start2 = (long long) i * i;
        long long j = max(start1, start2);
        if (j == start2) {
            divisors[j - L] += 1;
            j += i;
        }
        for ( ; j <= R; j += i) {
            divisors[j - L] += 2;
        }
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    long long L, R;
    cin >> L >> R;
    segment_sieve(L, R);
    for (long long i = L; i <= R; ++i) {  
        cout << divisors[i - L] << '\n'; 
    }

    return 0;
}