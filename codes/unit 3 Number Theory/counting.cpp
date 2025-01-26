class Combinatorics{
    public:
    static const int MAXN = 1000000;
    static const int MOD = 1000000007;
    static long long fact[MAXN], invfact[MAXN];
    static long long modpow(long long a, long long b, long long mod) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    static long long modinv(long long a, long long mod) {
        return modpow(a, mod - 2, mod);
    }
    static void init() {
        fact[0] = 1;
        for (int i = 1; i < MAXN; i++)
            fact[i] = fact[i - 1] * i % MOD;
        invfact[MAXN - 1] = modinv(fact[MAXN - 1], MOD);
        for (int i = MAXN - 2; i >= 0; i--)
            invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
    static long long C(int n, int k) {
        if (k < 0 || k > n)
            return 0;
        return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
    }
    static long long P(int n, int k) {
        if (k < 0 || k > n)
            return 0;
        return fact[n] * invfact[n - k] % MOD;
    }
};
