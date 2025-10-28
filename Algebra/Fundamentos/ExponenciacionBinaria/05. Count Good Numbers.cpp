class Solution {
public:
    int MOD = 1000000007; 
    long long binpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        int resp = (binpow(5, n/2 + (n&1)) * binpow(4, n/2)) % MOD;
        return resp;
    }
};

// https://leetcode.com/problems/count-good-numbers