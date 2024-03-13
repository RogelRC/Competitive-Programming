#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > matriz;
vector<int> visitado;
int nododmax, dmax;

void dfs(int n){
    if(visitado[n] > dmax){
        dmax = visitado[n];
        nododmax = n;
    }

    for(int i = 0; i < matriz[n].size(); i ++){
        int ady = matriz[n][i];

        if(visitado[ady] == -1){
            visitado[ady] = visitado[n] + 1;

            dfs(ady);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int nodos, a;

    while(cin >> nodos && nodos != -1){
        matriz.clear();
        visitado.clear();
        matriz.resize(nodos + 1);
        visitado.resize(nodos + 1, -1);

        for(int i = 2; i <= nodos; i ++){
            cin >> a;

            matriz[i].push_back(a);
            matriz[a].push_back(i);
        }

        visitado[1] = 0;
        nododmax = 1;
        dmax = 0;
        dfs(1);

        fill(visitado.begin(), visitado.end(), -1);
        visitado[nododmax] = 0;

        dfs(nododmax);

        if(dmax % 2 == 1) cout << dmax / 2 + 1 << "\n";
        else cout << dmax / 2 << "\n";

    }
    

    return 0;
}