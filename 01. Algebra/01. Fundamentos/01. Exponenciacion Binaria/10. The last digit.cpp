#include<bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

typedef long long lli;
const int MOD = 10;

lli binpow(lli a, lli p) {
    lli res = 1;
    while (p > 0) {
        if (p & 1) res *= a;
        a *= a;
        p >>= 1;
        res %= MOD;
        a %= MOD;
    }
    return res;
}

int solve() {
    lli a, b;
    cin >> a >> b;
    cout << binpow(a, b) << endl;
    return 0;
}

signed main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

// https://vjudge.net/problem#OJId=SPOJ&probNum=&title=The%20last%20digit&source=&category=all
// https://www.spoj.com/status/ns=35144959