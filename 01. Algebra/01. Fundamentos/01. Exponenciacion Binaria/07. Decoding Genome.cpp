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

const int MOD = 1000000007; // Módulo del problema, cambiar en caso de no ser ese. NO TIENE PORQUÉ SER CONSTANTE, SOLO GLOBAL

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

void Imprime_set(set<int> s) {
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int maximo_comun_divisor(int a, int b) {
    int temporal; // Para no perder b
    while (b != 0) {
        temporal = b;
        b = a % b;
        a = temporal;
    }
    return a;
}

int minimo_comun_multiplo(int a, int b) {
    return (a * b) / maximo_comun_divisor(a, b);
}

bool isNumeric(string const &str) {
    auto it = str.begin();
    while (it != str.end() && isdigit(*it)) {
        it++;
    }
    return !str.empty() && it == str.end();
}

void lee(int n, vi& vect) {
  rep(i, n) cin >> vect[i];
  return ;
}

#define INF INT_MAX
double pi = 2*acos(0.0);

map<char, int> nodes = {
    {'a', 0},
    {'b', 1},
    {'c', 2},
    {'d', 3},
    {'e', 4},
    {'f', 5},
    {'g', 6},
    {'h', 7},
    {'i', 8},
    {'j', 9},
    {'k', 10},
    {'l', 11},
    {'m', 12},
    {'n', 13},
    {'o', 14},
    {'p', 15},
    {'q', 16},
    {'r', 17},
    {'s', 18},
    {'t', 19},
    {'u', 20},
    {'v', 21},
    {'w', 22},
    {'x', 23},
    {'y', 24},
    {'z', 25},
    {'A', 26},
    {'B', 27},
    {'C', 28},
    {'D', 29},
    {'E', 30},
    {'F', 31},
    {'G', 32},
    {'H', 33},
    {'I', 34},
    {'J', 35},
    {'K', 36},
    {'L', 37},
    {'M', 38},
    {'N', 39},
    {'O', 40},
    {'P', 41},
    {'Q', 42},
    {'R', 43},
    {'S', 44},
    {'T', 45},
    {'U', 46},
    {'V', 47},
    {'W', 48},
    {'X', 49},
    {'Y', 50},
    {'Z', 51}
};

vector<vector<Mint>> multMatrix(vector<vector<Mint>>& matrix1, vector<vector<Mint>>& matrix2) {
    int n = matrix1.size();
    vector<vector<Mint>> newMatrix(n, vector<Mint>(n, 0));
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            for(int z=0; z<n; ++z)
                newMatrix[i][j] += matrix1[i][z] * matrix2[z][j];
    return newMatrix;
}

vector<vector<Mint>> powMatrix(vector<vector<Mint>>& matrix1, long long k) {
    vector<vector<Mint>> res(matrix1.size(), vector<Mint>(matrix1.size(), 0));
    for (int i = 0; i<res.size(); i++){
        res[i][i] = 1;
    }
    while (k > 0) {
        if (k & 1) {
            res = multMatrix(res, matrix1);
        }
        matrix1 = multMatrix(matrix1, matrix1);
        k >>= 1;
    }
    return res;
}

int solve() {
    // Code aquí
    lli n, m, k; // op, nucleos, parejas
    cin >> n >> m >> k;
    vector<vector<Mint>> grafo(m, vector<Mint>(m,1));
    string par;
    while(k--){
        cin >> par;
        grafo[nodes[par[0]]][nodes[par[1]]] = 0;
    }
    vector<vector<Mint>> resp = powMatrix(grafo, n-1);
    Mint ans = 0;
    for (int i = 0; i<resp.size(); i++){
        for (int j = 0; j<resp[i].size(); j++){
            ans += resp[i][j];
        }
    }

    cout << ans << endl;

    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    solve();
    return 0;
}

// https://vjudge.net/problem/CodeForces-222E