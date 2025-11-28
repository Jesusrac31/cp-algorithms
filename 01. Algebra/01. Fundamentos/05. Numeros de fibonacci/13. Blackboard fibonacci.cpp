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
template<typename T, typename Q> std::ostream& operator<<(std::ostream& os, const std::pair<T, Q>& p) {
    os << "(" << p.first << " ; " << p.second << ")";
    return os;
}

#define INF INT_MAX
double pi = 2*acos(0.0);

// 1. Función LIGERA solo para chequear (sin strings)
// Retorna el 'badness' si es válido, o INF si no lo es.
int checkSolution(int x, int y, int n) {
    int steps = 0;
    int badness = 0;
    
    // Algoritmo de Euclides modificado
    while (x > 0 && y > 0) {
        if (steps > n) return INF; 
        
        if (x >= y) {
            int count = x / y;
            // Ajuste para no pasar de (1,1) a (0,1)
            if (x % y == 0) { count--; if (count == 0) break; } // Estamos en (y, y)
            
            steps += count;
            badness += (count - 1);
            x %= y;
        } else {
            int count = y / x;
            if (y % x == 0) { count--; if (count == 0) break; }
            
            steps += count;
            badness += (count - 1);
            y %= x;
        }
    }
    
    // Validaciones estrictas
    if (steps != n - 1) return INF;   // Debe usar exactamente n-1 transiciones
    
    return badness;
}

// 2. Función para reconstruir el string (se llama SOLO UNA VEZ al final)
string buildString(int x, int y) {
    string s = "";
    while (x > 0 && y > 0) {
        if (x >= y) {
            int count = x / y;
            if (x % y == 0) { count--; if (count == 0) break; }
            // OJO: Invertimos lógica de letras vs código anterior
            // Si x > y, venimos de un Top, agregamos T
            for(int k=0; k<count; k++) s += 'T';
            x %= y;
        } else {
            int count = y / x;
            if (y % x == 0) { count--; if (count == 0) break; }
            for(int k=0; k<count; k++) s += 'B';
            y %= x;
        }
    }
    reverse(s.begin(), s.end());
    s = "T" + s;
    if (s[1] == 'T'){
        for (int i = 1; i<s.size(); i++){
            if (s[i] == 'T'){
                s[i] = 'B';
            } else {
                s[i] = 'T';
            }
        }
    }
    return s;
}

int solve() {
    int n, r;
    cin >> n >> r;
    
    // Caso borde n=1 (no hay transiciones)
    if (n==1 && r==1) { cout << "0\nT" << endl; return 0; }

    int min_badness = INF;
    int best_h = -1;

    // Solo iteramos la altura h
    for (int h = 1; h <= r; h++) {
        // Filtro rápido: deben ser coprimos
        if (__gcd(r, h) != 1) continue;

        int b = checkSolution(r, h, n);
        
        if (b < min_badness) {
            min_badness = b;
            best_h = h;
        }
    }

    if (min_badness == INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << min_badness << endl;
        cout << buildString(r, best_h) << endl;
    }
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    solve();
    return 0;
}

// https://vjudge.net/problem/CodeForces-217B
// https://codeforces.com/problemset/problem/217/B