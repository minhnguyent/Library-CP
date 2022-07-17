// https://www.codechef.com/problems/PRETNUM

#include <iostream>
#include <vector>

using namespace std;

const int N = (int) 1e7;
vector<int> primes;
int spf[N + 3];
bool is_prime[N + 3];

void sieve(int n) {
    primes.assign(1, 2);
    is_prime[2] = true;
    spf[0] = spf[1] = -1;
    for (int i = 2; i <= n; ++i) spf[i] = 2;

    for (int x = 3; x <= n; x += 2) {
        if (spf[x] == 2) {
            primes.push_back(spf[x] = x);
            is_prime[x] = true;
        }
        for (int &p : primes) {
            if (p > spf[x] || 1LL * x * p > n) break;
            spf[x * p] = p;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    sieve(N);

    return 0;
}