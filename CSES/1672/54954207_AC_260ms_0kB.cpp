#include <bits/stdc++.h>

using namespace std;

#define INF INT64_MAX / 2

long long matriz[505][505];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long nodos, aristas, querys, e1, e2, p;

    cin >> nodos >> aristas >> querys;

    for(long long i = 1; i <= nodos; i ++){
        for(long long j = i; j <= nodos; j ++){
            if(i == j) matriz[i][j] == 0;
            else matriz[i][j] = matriz[j][i] = INF;
        }
    }

    while(aristas --){
        cin >> e1 >> e2 >> p;

        matriz[e1][e2] = matriz[e2][e1] = min(matriz[e1][e2], p);
    }

    for(long long i = 1; i <= nodos; i ++){
        for(long long j = 1; j <= nodos; j ++){
            for(long long k = 1;k <= nodos; k ++){
                matriz[j][k] = min(matriz[j][k], matriz[j][i] + matriz[i][k]);
            }
        }
    }

    while(querys --){
        cin >> e1 >> e2;

        cout << (matriz[e1][e2] != INF ? matriz[e1][e2]: -1) << "\n";
    }

    return 0;
}