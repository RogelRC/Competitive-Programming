#include <bits/stdc++.h>

using namespace std;

vector<vector<long long> > matriz;
vector<bool> visitado;
vector<long long> dp;

void DFS(long long actual){
    visitado[actual] = true;

    long long ady = 0;

    for(long long i = 0; i < matriz[actual].size(); i ++){
        if(visitado[matriz[actual][i]] == false){
            DFS(matriz[actual][i]);

            ady += dp[matriz[actual][i]];
        }
    }

    if(ady == 0) dp[actual] = 1;
    else dp[actual] = ady;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long casos, nodos, e1, e2, querys;

    cin >> casos;

    while(casos --){
        cin >> nodos;

        matriz.clear();
        visitado.clear();
        dp.clear();

        matriz.resize(nodos + 1);
        visitado.resize(nodos + 1);
        dp.resize(nodos + 1);

        for(long long i = 1; i < nodos; i ++){
            cin >> e1 >> e2;

            matriz[e1].push_back(e2);
            matriz[e2].push_back(e1);
        }

        DFS(1);

        cin >> querys;

        while(querys --){
            cin >> e1 >> e2;

            cout << dp[e1] * dp[e2] << "\n";
        }
    }

    return 0;
}