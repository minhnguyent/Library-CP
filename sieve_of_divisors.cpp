#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int N = (int) 1e6;
int divisors1[N + 3];
int divisors2[N + 3];

void sieve1(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            divisors1[j]++;
        }
    }
    // Time complexity: O(NlogN)
    // https://discuss.codechef.com/t/more-intuitive-explanation-for-the-harmonic-seriess-sum/67287
}

void sieve2(int n) {
    for (int i = 1, _sqrt = sqrt(n); i <= _sqrt; ++i) {
        divisors2[i * i] += 1;
        for (int j = i * (i + 1); j <= n; j += i) {
            divisors2[j] += 2;
        }
    }
    // Better than O(NlogN)
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    sieve1(N);
    sieve2(N);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {  
        if (divisors1[i] != divisors2[i]) {
            cout << "Wrong answer at i = " << i << '\n';
            cout << divisors1[i] << " != " << divisors2[i] << '\n';
            break;
        }
    }

    return 0;
}