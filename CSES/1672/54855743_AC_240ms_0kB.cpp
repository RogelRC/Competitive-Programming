#include <bits/stdc++.h>

#define INF (INT64_MAX / 2)

using namespace std;

long long nodos, aristas, querys, a, b, c;
long long matriz[505][505];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> nodos >> aristas >> querys;

    for(long long i = 0; i <= nodos; i ++){
        for(long long j = i; j <= nodos; j ++){
            if(i == j) matriz[i][j] = 0;
            else matriz[i][j] = matriz[j][i] = INF;
        }
    }

    while(aristas --){
        cin >> a >> b >> c;

        matriz[a][b] = matriz[b][a] = min(matriz[a][b], c);
    }

    for(long long i = 1; i <= nodos; i ++){
        for(long long j = 1; j <= nodos; j ++){
            for(long long k = 1; k <= nodos; k ++){
                matriz[j][k] = min(matriz[j][k], matriz[j][i] + matriz[i][k]);
            }
        }
    }

    while(querys --){
        cin >> a >> b;

        if(matriz[a][b] == INF) cout << -1 << "\n";
        else cout << matriz[a][b] << "\n";
    }

    return 0;
}