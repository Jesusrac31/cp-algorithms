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
#define borra(vect, n) vect.erase(vect.begin() + n);
#define copia(v1, v2)                                                                                                                    \
    ;                                                                                                                                                        \
    copy(v1.begin(), v1.end(), back_inserter(v2));

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

const int MOD = 1000000007;

struct Mint { 
    int v;
    Mint(long long val = 0) {
        v = int(val % MOD);
        if (v < 0) v += MOD;
    }
    bool operator==(const Mint& other) const { return this->v == other.v; }
    bool operator!=(const Mint& other) const { return !(*this == other); }
    Mint operator+(const Mint &o) const { return Mint(v + o.v); }
    Mint operator-(const Mint &o) const { return Mint(v - o.v); }
    Mint operator*(const Mint &o) const { return Mint(1LL * v * o.v); }
    Mint operator/(const Mint &o) const { return *this * o.inv(); }
    Mint& operator+=(const Mint &o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    Mint& operator-=(const Mint &o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    Mint& operator*=(const Mint &o) { v = int(1LL * v * o.v % MOD); return *this; }
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

#define tipoMatrix Mint
#define defaultValue 0
struct matrix {
    int filas;
    int columnas;
    vector<vector<tipoMatrix>> m;
    matrix(int f=2, int c=2, tipoMatrix value = defaultValue){
        filas = f;
        columnas = c;
        m = vector<vector<tipoMatrix>>(filas, vector<tipoMatrix>(columnas, value));
    }
    matrix (const vector<vector<tipoMatrix>>& x){
        m=x;
        filas = m.size();
        columnas = m[0].size();
    }
    vector<tipoMatrix>& operator[](int index) { return m[index]; }
    const vector<tipoMatrix>& operator[](int index) const { return m[index]; }
    bool operator==(const matrix& other) const { 
        return filas == other.filas &&
               columnas == other.columnas &&
               m == other.m; 
    }
    bool operator!=(const matrix& other) const { return !(m == other.m); }
    matrix& operator= (const matrix &matrix1) { 
        if (this == &matrix1) return *this;
        m = matrix1.m;
        this->filas = matrix1.filas;
        this->columnas = matrix1.columnas;
        return *this;
    }
    matrix friend operator +(const matrix &matrix1, const matrix &matrix2){
        matrix newMatrix(matrix1.filas, matrix1.columnas);
        for(int i=0; i<matrix1.filas; ++i)
            for(int j=0; j<matrix1.columnas; ++j)
                newMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        return newMatrix;
    }
    matrix friend operator -(const matrix &matrix1, const matrix &matrix2){
        matrix newMatrix(matrix1.filas, matrix1.columnas);
        for(int i=0; i<matrix1.filas; ++i)
            for(int j=0; j<matrix1.columnas; ++j)
                newMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        return newMatrix;
    }
    matrix friend operator *(const matrix &matrix1, const matrix &matrix2){
        matrix newMatrix(matrix1.filas, matrix2.columnas);
        for(int i=0; i<matrix1.filas; ++i)
            for(int j=0; j<matrix2.columnas; ++j)
                for(int z=0; z<matrix2.filas; ++z)
                    newMatrix[i][j] += matrix1[i][z] * matrix2[z][j];
        return newMatrix;
    }
    matrix pow(long long k) const {
        matrix base = *this;
        matrix res(filas, columnas, 0);
        for (int i = 0; i < filas; i++) res[i][i] = 1;
        while (k > 0) {
            if (k & 1) res = res * base;
            base = base * base;
            k >>= 1;
        }
        return res;
    }
    friend ostream& operator<<(ostream& os, const matrix& m) {
        for(int i=0; i<m.filas; ++i){
            for(int j=0; j<m.columnas; ++j)
                os << m[i][j] << " ";
            os << "\n";
        }            
        return os;
    }
};

#define INF INT_MAX
double pi = 2*acos(0.0);

int solve() {
    long long n, m;
    cin >> n >> m;
    matrix base = matrix({{1, 1} , {1, 0}});
    matrix sumM = base.pow(m+2);
    base = matrix({{1, 1} , {1, 0}});
    matrix sumN = base.pow(n+2);
    cout << sumM[0][1] - sumN[1][1] << endl;
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

// https://vjudge.net/problem/SPOJ-FIBOSUM
// https://www.spoj.com/problems/FIBOSUM