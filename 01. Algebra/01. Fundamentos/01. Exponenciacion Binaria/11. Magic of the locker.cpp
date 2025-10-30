#include<bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

typedef long long lli;

const int MOD = 1000000007;

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
    // Code aquí
    lli n;
    cin >> n;
    if (n <= 3){
        cout << n << endl;
    } else if (n%3 == 0){
        cout << binpow(3, n/3) << endl;
    } else if (n%3 == 1){
        cout << ((binpow(3, (n/3)-1)*4)%MOD) << endl;
    } else {
        cout << ((binpow(3, (n/3))*2)%MOD) << endl;
    }
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    int T;
    cin >> T; // Número de casos
    while (T--) {
        solve();
    }
    return 0;
}

// https://vjudge.net/problem/SPOJ-LOCKER
// https://www.spoj.com/status/ns=35145347