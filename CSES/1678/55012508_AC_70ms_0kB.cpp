#include <bits/stdc++.h>
using namespace std;

#define NMAX 100005

vector<int> matriz[NMAX];
int padre[NMAX];
int visitado[NMAX], trip[NMAX];
int nodos, aristas, e1, e2, ini, fin;
vector<int> sol;

void dfs(int actual){
    visitado[actual] = 1;

    for(int &i: matriz[actual]){

        if(visitado[i] == 0){
            padre[i] = actual;
            dfs(i);

            if(ini != 0) return;
        }
        else if(visitado[i] == 1){
            fin = actual;
            ini = i;
            return;
        }
    }
    visitado[actual] = 2;
}

void camino(int actual){
    if(actual == ini) return;
    sol.push_back(actual);
    camino(padre[actual]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> nodos >> aristas;

    while(aristas --){
        cin >> e1 >> e2;

        matriz[e1].push_back(e2);
    }

    for(int i = 1; i <= nodos; i ++){
        if(visitado[i] == 0) dfs(i);
        if(ini != 0) break;
    }

    if(ini != 0){
        sol.push_back(ini);
        camino(fin);
        sol.push_back(ini);

        cout << sol.size() << "\n";

        for(int i = sol.size() - 1; i >= 0; i --){
            cout << sol[i] << " ";
        }
    }
    else cout << "IMPOSSIBLE";

    return 0;
}