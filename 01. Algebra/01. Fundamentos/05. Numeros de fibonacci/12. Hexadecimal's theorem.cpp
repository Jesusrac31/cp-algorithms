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

#define INF INT_MAX
double pi = 2*acos(0.0);

#define MAX_INDEX 42

int solve() {
    // Code aquí
    int n;
    cin >> n;

    pii pareja = {701408733, 1134903170};
    int counter = 0;
    vi sol = {};
    for (int i = MAX_INDEX; i>=0 && counter < 3; i--){
        while (pareja.first <= n){
            n-=pareja.first;
            counter++;
            sol.PB(pareja.first);
        }
        int tmp = pareja.second;
        pareja.second = pareja.first;
        pareja.first = tmp-pareja.first;
    }
    if (n == 0){
        while(sol.size() < 3){
            sol.PB(0);
        }
        cout << sol[0] << " " << sol[1] << " " << sol[2] << endl;
    } else {
        cout << "I'm too stupid to solve this problem" << endl;
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

// https://vjudge.net/problem/CodeForces-199A
// https://codeforces.com/problemset/problem/199/A