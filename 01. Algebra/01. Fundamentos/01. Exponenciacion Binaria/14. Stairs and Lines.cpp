#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include<bits/stdc++.h>
#include<unordered_set>
//#pragma GCC optimize("O3")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

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
    os << "]\n";
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
#define LEN 7
#define Col vector<Mint>
#define Matrix vector<Col>

vi Power2 = {1, 2, 4, 8, 16, 32, 64, 128}; 

// Generar matrices de transición
lli getPosibilidades(int MaskA, int MaskB, int tamano, int index = 1, int prev = 1){
    //cout << "Branch process: index-> " << index << " tamano-> " << tamano << endl;
    if (index == tamano){
        //cout << "End Branch: " << (!((MaskA & Power2[index-1]) && (MaskB & Power2[index-1]) && prev)) << endl;
        return (!((MaskA & Power2[index-1]) && (MaskB & Power2[index-1]) && prev));
    }
    lli resp = 0;
    resp += getPosibilidades(MaskA, MaskB, tamano, index+1, 0);
    // Si la arista de la izquierda existe, la de la derecha existe y la de abajo tambien, no podemos fijar a 1 esta arista horizontal
    if (!((MaskA & Power2[index-1]) && (MaskB & Power2[index-1]) && prev)){  
        resp += getPosibilidades(MaskA, MaskB, tamano, index+1, 1);
    }

    return resp;
}

int GenerateMatrix (Matrix & Mat, int a, int b){
    int combA = Power2[a]; // Número de máscaras de altura a
    int combB = Power2[b]; // Número de máscaras de altura b

    int offset = 0;
    if (a<b){
        for (int j = a; j<b; j++){
            offset+=Power2[j];
        }
    }
    
    for (int i = 0; i<combA; i++){
        Mat.PB({});
        for (int j = 0; j<combB; j++){
            Mat[i].PB(0);
            Mat[i][j] = Mint(getPosibilidades(i+offset, j, b));
        }
    }
}

int GenerateTrans (vector<vector<Matrix>> & Transiciones){
    // Genera transiciones 0, i
    for (int i = 1; i<=LEN; i++){
        Transiciones[0][i] = Matrix(1, Col(Power2[i], 0));
        Transiciones[0][i][0][Power2[i]-1] = 1;
    }

    // Otras transiciones
    for (int i = 1; i<=LEN; i++){
        for (int j = i; j<=LEN; j++){
            GenerateMatrix(Transiciones[i][j], i, j);
        }
    }
    return 0;
}

// Operaciones con matrices
vector<vector<Mint>> multMatrix(vector<vector<Mint>>& matrix1, vector<vector<Mint>>& matrix2) {
    int n = matrix1.size();
    int m = matrix2[0].size();
    int l = matrix2.size();
    vector<vector<Mint>> newMatrix(n, vector<Mint>(m, 0));
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            for(int z=0; z<l; ++z)
                newMatrix[i][j] += matrix1[i][z] * matrix2[z][j];
    return newMatrix;
}

vector<vector<Mint>> powMatrix(vector<vector<Mint>> matrix1, long long k) {
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
    vi w(LEN+1);
    for (int i = 1; i<=LEN; i++){
        cin >> w[i];
    }

    // El tamaño de cada escalón viene dado por un número del 1 al 7 al que llamaremos h, 
    // lo que significa que ese escalón tiene a su derecha h aristas verticales y a su izquierda tendrá tantas como altura tenga el bloque de la izquierda.
    // Partiendo de esto, necesitamos una matriz que nos indique el número de combinaciones válidas que tenemos dado 2 máscaras verticales que nos dicen como establecer las aristas de la derecha y la izquierda de la columna.
    // Estas máscaras tienen 2^h posibilidades, en el peor de los caso 2^7 = 128. Por lo que serían matrices de como mucho 128x128
    // A cada una de estas combinaciones de máscaras obtendremos cuantas combinaciones válidas de aristas horizontales existen, siendo el número de aristas horizontales h-1 (la primera y la última son fijas) 
    vector<vector<Matrix>> Transiciones(LEN+1, vector<Matrix>(LEN+1)); 
    GenerateTrans(Transiciones);

    // Ahora, tenemos que computar la lista según el ancho:
    // Inicializamos la matriz solución (solo tiene una fila y 128 columnas, donde solo son accesibles las que su representacion binaria sea entero 1)
    int ant_h = 0; // Lleva la cuenta de cual escalón fue el último procesado
    bool primer = true; // Si es la primera aparición
    Matrix ans = Matrix(1, Col(Power2[LEN], 0));
    ans[0][0] = 1;

    // Procesamos las multiplicaciones
    for (int i = 1; i<=LEN; i++){
        // Checkea si hacemos algun paso:
        if (w[i]){
            // Procesa la transición
            ans = multMatrix(ans, Transiciones[ant_h][i]);

            // Recorre el resto de escalones
            Matrix PoweredMatrix = powMatrix(Transiciones[i][i], w[i]+primer-1);
            ans = multMatrix(ans, PoweredMatrix);
            
            ant_h = i;
            if (primer){
                primer = false;
            }
        }
    }
    cout << ans[0][Power2[ant_h]-1] << endl;

    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    solve();
    return 0;
}

// https://vjudge.net/problem/CodeForces-498E
// https://codeforces.com/contest/498/problem/E