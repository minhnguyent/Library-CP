#include <iostream>
#include <vector>

using namespace std;

const int MOD = (int) 1e9 + 7;

// See: https://github.com/nealwu/competitive-programming/
// Consult Prefix/Posfix Increment/Decrement: https://docs.microsoft.com/vi-vn/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-170

template<const int &MOD>
struct Mint {
    int val;

    Mint() {}
    Mint(long long v) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = v;
    }
    Mint(unsigned long long v) {
        if (v >= MOD) v %= MOD;
        val = v;
    }
    Mint(int v) : Mint((long long)v) {}
    Mint(unsigned int v) : Mint((unsigned long long)v) {}

    Mint& operator+=(const Mint &other) {
        val += other.val - MOD;
        if (val < 0) val += MOD;
        return *this;
    }

    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    Mint& operator*=(const Mint &other) {
        val = (1ll * val * other.val) % MOD;
        return *this;
    }

    Mint& operator/=(const Mint &other) {
        (*this) *= other.inverse();
        return *this;
    }

    friend Mint operator+(const Mint &a, const Mint &b) {
        return Mint(a) += b;
    }
    friend Mint operator-(const Mint &a, const Mint &b) {
        return Mint(a) -= b;
    }
    friend Mint operator*(const Mint &a, const Mint &b) {
        return Mint(a) *= b;
    }
    friend Mint operator/(const Mint &a, const Mint &b) {
        return Mint(a) /= b;
    }

    Mint& operator++() {
        // ++a
        val = (val == MOD - 1 ? 0 : val + 1);
        return *this;
    }

    Mint &operator--() {
        // --a
        val = (val == 0 ? MOD - 1 : val - 1);
        return *this;
    }

    Mint operator++(int) {
        // a++
        Mint prev = *this; ++(*this); return prev;
    }
    Mint operator--(int) {
        // a--
        Mint prev = *this; --(*this); return prev;
    }

    friend bool operator==(const Mint &a, const Mint &b) { return a.val == b.val; }
    friend bool operator!=(const Mint &a, const Mint &b) { return a.val != b.val; }
    friend bool operator<(const Mint &a, const Mint &b) { return a.val < b.val; }
    friend bool operator<=(const Mint &a, const Mint &b) { return a.val <= b.val; }
    friend bool operator>(const Mint &a, const Mint &b) { return a.val > b.val; }
    friend bool operator>=(const Mint &a, const Mint &b) { return a.val >= b.val; }

    // Modular inverse
    // See here: https://cp-algorithms.com/algebra/module-inverse.html#MOD-inv-all-num
    // And here: https://discuss.codechef.com/t/guide-to-modular-arithmetic-plus-tricks-codechef-edition-there-is-no-other-edition/67424

    static const int MAXN = (int)1e6 + 3;
    static Mint inv[MAXN]; // make sure MOD is prime

    static void pre_compute_inverse() {
        inv[1] = 1;
        for (int t = 2; t < MAXN; ++t) {
            inv[t] = inv[MOD % t] * (MOD - MOD / t);
        }
    }

    Mint inverse() const {
        if (inv[1] == 0) {
            pre_compute_inverse();
        }
        if (val < MAXN) {
            return inv[val];
        }

        int curr = val;
        Mint product = 1;
        while (curr >= MAXN) {
            product *= (MOD - MOD / curr);
            curr = MOD % curr;
        }
        return inv[curr] * product;
    }

    Mint pow(long long n) const {
        Mint res = 1, v;
        if (n < 0) {
            n = -n; v = this -> inverse();
        }
        else v = *this;

        while (n > 0) {
            if (n & 1) res *= v;
            v *= v;
            n >>= 1;
        }
        return res;
    }
    void swap(Mint &other) {
        swap(val, other.val);
    }

    friend ostream& operator<<(ostream &os, const Mint &a) {
        return os << a.val;
    }

};
template<const int &MOD> Mint<MOD> Mint<MOD>::inv[Mint<MOD>::MAXN]; 
using mint = Mint<MOD>;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int a = 10;
    mint mint_a = a;
    cout << mint_a << '\n';   

    return 0;
}