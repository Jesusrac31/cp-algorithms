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

#define INF LONG_LONG_MAX
double pi = 2*acos(0.0);
typedef __int128_t i128;

const lli MOD = 1e13;

pair<i128, i128> fibPair(long long n) {
    if (n == 0) return {0, 1};
    auto p = fibPair(n >> 1);
    i128 a = p.first%MOD;
    i128 b = p.second%MOD;
    i128 c = (a * ((2*b)%MOD - a + MOD)%MOD)%MOD;
    i128 d = ((a*a)%MOD + (b*b)%MOD)%MOD;
    if (n & 1) return {d%MOD, (c + d)%MOD};
    else return {c%MOD, d%MOD};
}

pair<long long, long long> getFibo(long long k, pair<long long, long long> basell) {
    pair<long long, long long> sol;
    pair<i128, i128> inc = fibPair(k-1);
    pair<i128, i128> base = basell;
    sol.first = ((base.first*inc.first)%MOD+(base.second*inc.second)%MOD)%MOD;
    sol.second = ((base.first*(inc.second))%MOD+(base.second*(inc.first + inc.second)%MOD)%MOD)%MOD;
    return sol;
}


lli periodoPisano10(lli x){
    if (x == 1){
        return 1;
    } else if (x == 10){
        return 60;
    } else if (x == 100) {
        return 300;
    } else {
        return 15*x/10;
    }
}

void getNewCandidates(unordered_map<lli, pair<lli, lli>>& candidatos, unordered_map<lli, pair<lli, lli>>& newCandidatos, lli newModulo, lli f){
    lli antModulo = newModulo/10;
    lli antPeriodo = periodoPisano10(antModulo);
    lli newPeriodo = periodoPisano10(newModulo);
    newCandidatos.clear();
    for (auto p:candidatos){
        lli x = p.first;
        pair<lli, lli> valueCandidato = p.second;
        for (lli k = 0; x+k*antPeriodo<newPeriodo; k++){
            lli candidato = x+k*antPeriodo;
            if (valueCandidato.first % newModulo == f % newModulo){
                newCandidatos[candidato] = valueCandidato;
            }
            valueCandidato = getFibo(antPeriodo, valueCandidato);
        }
    }
    return ;
}

int solve() {
    // Code aquí
    lli f;
    cin >> f;
    unordered_map<lli, pair<lli, lli>> candidatos = {{0, {0, 1}}}; // posicion, {valor, valor sig}
    unordered_map<lli, pair<lli, lli>> newCandidatos;
    for (lli newModulo = 10; newModulo<=MOD; newModulo*=10){
        getNewCandidates(candidatos, newCandidatos, newModulo, f);
        swap(candidatos, newCandidatos);
    }
    lli sol = INF;
    for (auto x:candidatos){
        sol = min(sol, x.first);
    }

    cout << (candidatos.size() ? sol:-1) << endl;

    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    solve();
    return 0;
}

// https://vjudge.net/problem/CodeForces-193E
// https://codeforces.com/problemset/problem/193/E