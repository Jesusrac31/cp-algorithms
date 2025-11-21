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

long long getFibo(int index){
    long double aureo = ((1+sqrt(5))/2);
    long double res = 1;
    while (index > 0) {
        if (index & 1)
            res = res * aureo;
        aureo = aureo * aureo;
        index >>= 1;
    }
    return ((long long) (round(res/sqrt(5))));
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
    lli n;
    cin >> n;

    lli sol = findNFibo(n);

    cout << (getFibo(sol) == n ? "IsFibo":"IsNotFibo") << endl;

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

// https://vjudge.net/problem/HackerRank-is-fibo
// https://www.hackerrank.com/challenges/is-fibo/problem