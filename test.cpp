#include<bits/stdc++.h>

using namespace std;

typedef long long lli;
#define int lli

int node_init;
vector<pair<int, char>> other_nodes;
char wall = '#',
     path = '.',
     start = 'S',
     other = 'O';

vector<vector<int>> MapToGraph(vector<string> tablero) {
    vector<vector<int>> grafo(tablero.size());
    int n = tablero.size(), m = tablero[0].size();
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            if (tablero[i][j] != wall){
                if (j!=0 && tablero[i][j-1] != wall){
                    grafo[i*m+j].emplace_back(i*m+j-1);
                }
                if (j!=m-1 && tablero[i][j+1] != wall){
                    grafo[i*m+j].emplace_back(i*m+j+1);
                }
                if (i!=0 && tablero[i-1][j] != wall){
                    grafo[i*m+j].emplace_back((i-1)*m+j);
                }
                if (i!=n-1 && tablero[i+1][j] != wall){
                    grafo[i*m+j].emplace_back((i+1)*m+j);
                }
            }
            if (tablero[i][j] == start){
                node_init = i*m+j;
            }
            if (tablero[i][j] == other){
                other_nodes.emplace_back(i*m+j);
            }
        }   
    }
    return grafo;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    

    return 0;
}