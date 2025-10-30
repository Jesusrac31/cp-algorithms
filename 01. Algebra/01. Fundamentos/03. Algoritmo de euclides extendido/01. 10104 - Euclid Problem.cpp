#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2")

#ifdef DEBUG
#include "lib/debug.h"
#else
#define debug(...) 228
#endif

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long lli;
typedef pair<int, int> pii;
typedef map<string, int> msi;
typedef map<int, vector<int>> miv;


lli gcd(lli a, lli b, lli& x, lli& y) {
    x = 1, y = 0;
    lli x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        lli q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

lli solve(lli a, lli b) {
    // Code aquí
    lli x, y;
    lli maxComDiv = gcd(a, b, x, y);
    cout << x << " " << y << " " << maxComDiv << endl;
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    lli a, b;
    while (cin >> a >> b) {
        solve(a, b);
    }
    return 0;
}

// https://vjudge.net/problem/UVA-10104
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045