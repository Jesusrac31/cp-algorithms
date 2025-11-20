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

const int MOD = 998244353; // Módulo del problema, cambiar en caso de no ser ese. NO TIENE PORQUÉ SER CONSTANTE, SOLO GLOBAL

struct Mint { // Es una estructura como el int pero que trabaja en mod MOD
    int v;
    Mint(long long val = 0) {
        v = int(val % MOD);
        if (v < 0) v += MOD;
    }
    Mint operator+(const Mint &o) const { return Mint(v + o.v); }
    Mint operator-(const Mint &o) const { return Mint(v - o.v); }
    Mint operator*(const Mint &o) const { return Mint(1LL * v * o.v); }
    Mint operator/(const Mint &o) const { return *this * o.inv(); }
    Mint& operator+=(const Mint &o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    Mint& operator-=(const Mint &o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    Mint& operator*=(const Mint &o) { v = int(1LL * v * o.v % MOD); return *this; }
    bool operator<(const Mint& o) const {return v < o.v;}
    bool operator>(const Mint& o) const {return v > o.v;}
    bool operator==(const Mint& o) const {return v == o.v;}
    bool operator!=(const Mint& o) const {return v != o.v;}
    Mint pow(long long p) const {
        Mint a = *this, res = 1;
        while (p > 0) {
            if (p & 1) res *= a;
            a *= a;
            p >>= 1;
        }
        return res;
    }
    Mint inv() const { return pow(MOD - 2); }
    friend ostream& operator<<(ostream& os, const Mint& m) {
        os << m.v;
        return os;
    }
};
istream& operator>>(std::istream& input, Mint& m) {
    input >> m.v;
    return input;
}
template<typename T> std::ostream& operator<<(std::ostream& os, const Mint& m) {
    os << m.v << " ";
    return os;
}

// Funciones vector
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
#define borra_el(vect, el) vect.erase(vect.find(el));
#define borra_range(vect, a, b) vect.erase(a, b);
#define borra(vect, n) vect.erase(vect.begin() + n);
#define B begin();
#define E end();
#define copia(v1, v2)                                                                                                                    \
    ;                                                                                                                                                        \
    copy(v1.begin(), v1.end(), back_inserter(v2));

// Funciones pair
#define F first;
#define S second;

// Logaritmo de 2
double log_2 = log(2);
double log2(int a) { return (log(a) / log_2); }

// Imprime cualquier vector 
template<typename T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[ ";//Quita esto si no quieres los corchetes o cambia lo que quieras poner
    for(const auto& elem : vec) {
        os << elem << " ";
    }
    os << "]";
    return os;
}

#define INF INT_MAX
double pi = 2*acos(0.0);
#define int lli

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

int solsDiopEq(int a, int b, int p, int x_min=0, int x_max=INF, int y_min = 0, int y_max = INF){
    if (x_min > x_max || y_min > y_max) return 0;
    if (a == 0 && b == 0 && p == 0) return ((x_max-x_min+1)*(y_max-y_min+1));
    if (a == 0 && b == 0) return 0;
    if (a == 0){
        if (p%b == 0 && y_min <= p/b && y_max >= p/b && x_max-x_min+1 > 0) return (x_max-x_min+1);
        return 0;
    }
    if (b == 0){
        if (p%a == 0 && x_min <= p/a && x_max >= p/a && y_max-y_min+1 > 0) return (y_max-y_min+1);
        return 0;
    }
    int x0, y0;
    int d = gcd(a,b,x0,y0);
    if (p%d != 0) return 0;
    x0 *= p/d;
    y0 *= p/d;
    long double RX_min=((long double)(x_min-x0)*d)/b;
    long double RY_min=((long double)(y0-y_max)*d)/a;
    long double RX_max=((long double)(x_max-x0)*d)/b;
    long double RY_max=((long double)(y0-y_min)*d)/a;
    if (RY_min > RY_max) swap(RY_min, RY_max);
    if (RX_min > RX_max) swap(RX_min, RX_max);
    int range_min = ceil(max(RX_min, RY_min));
    int range_max = floor(min(RX_max, RY_max));
    if (range_max-range_min+1>0) return (range_max-range_min+1);
    else return 0;
}

int solve() {
    // Code aquí
    int a, b, c;
    cin >> a >> b >> c;
    cout << (solsDiopEq(a,b,c) ? "Yes" : "No") << endl;
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    solve();
    return 0;
}

// https://vjudge.net/problem/CodeForces-633A
// https://codeforces.com/contest/633/problem/A