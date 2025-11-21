#include<bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2")

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long lli;
typedef pair<int, int> pii;
typedef map<string, int> msi;
typedef map<int, vector<int>> miv;

#define PB(a) push_back(a);

bool sort_func(int a, int b) {
    if (a < b) {
        return true;
    } else {
        return false;
    }
}
#define ord(vect) sort(vect.begin(), vect.end(), sort_func)
#define rep(x,n) for(int x = 0; x < n; ++x)
#define borra(vect, n) vect.erase(vect.begin() + n);
#define copia(v1, v2)                                                                                                                    \
    ;                                                                                                                                                        \
    copy(v1.begin(), v1.end(), back_inserter(v2));

double log_2 = log(2);
double log2(int a) { return (log(a) / log_2); }

template<typename T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[ ";
    for(const auto& elem : vec) {
        os << elem << " ";
    }
    os << "]";
    return os;
}

#define INF INT_MAX
double pi = 2*acos(0.0);

#define MAX_FIB 92

pair<long long, long long> fibPair(long long n) {
    if (n == 0) return {0, 1};
    auto p = fibPair(n >> 1);
    long long a = p.first;
    long long b = p.second;
    long long c = a * (2*b - a);
    long long d = a*a + b*b;

    if (n & 1) return {d, c + d};
    else return {c, d};
}

long long getFibo(long long n) {
    return fibPair(n).first;
}

long long findNFibo(long long n){
    long long x = n;
    long long l = 0, r = MAX_FIB;
    while (r - l > 1) { 
        long long mid = (l + r) / 2;
        if (getFibo(mid)<=x) l = mid;
        else r = mid;
    }
    return l;
}

int solve() {
    long long n;
    cin >> n;

    long long index = findNFibo(n);
    long long sol;
    if (index % 3 == 1){
        index--;
    } else if (index % 3 == 2){
        index -= 2;
    }
    sol = getFibo(index+2)/2;
    cout << sol << endl;

    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

// https://vjudge.net/problem/HackerRank-euler002
// https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem