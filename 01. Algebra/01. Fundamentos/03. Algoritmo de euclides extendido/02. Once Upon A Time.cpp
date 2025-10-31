#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include<bits/stdc++.h>
#include<unordered_set>
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

#define int lli

#define INF INT_MAX

int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int solve(int n, int m, int a, int k) {
    // Code aquí
    k = k+a;
    int x, y;
    int d = gcd(m, a, x, y);

    if ((abs(n-k) % d) != 0){
        cout << "Impossible" << endl;
        return 0;
    }
    int t = (k-n)/d;
    x*=t;
    y*=-t;
    int param = max(ceil((double)(-d*x)/a), ceil((double)(-d*y)/m));

    x = x + param*(a/d);
    y = y + param*(m/d);

    cout << m*x+n << endl;

    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    int n, m, a, k;
    while (cin >> n >> m >> a >> k, n|m|a|k) {
        solve(n, m, a, k);
    }
    return 0;
}

// https://vjudge.net/problem/Gym-100963J
// https://codeforces.com/gym/100963