#include <bits/stdc++.h>

using namespace std;

int filas, columnas;
vector<vector<bool> > matriz;
short dp[1005][1005][4];

bool derecha(int x, int y){
    if(x < 0 || y < 0 || x >= filas || y >= columnas) return false;

    if(matriz[x][y] == true) dp[x][y][0] = true;
    if(dp[x][y][0] != -1) return dp[x][y][0];

    dp[x][y][0] = derecha(x, y + 1);

    return dp[x][y][0];
}

bool izquierda(int x, int y){
    if(x < 0 || y < 0 || x >= filas || y >= columnas) return false;

    if(matriz[x][y] == true) dp[x][y][1] = true;
    if(dp[x][y][1] != -1) return dp[x][y][1];

    dp[x][y][1] = izquierda(x, y - 1);

    return dp[x][y][1];
}

bool arriba(int x, int y){
    if(x < 0 || y < 0 || x >= filas || y >= columnas) return false;

    if(matriz[x][y] == true) dp[x][y][2] = true;
    if(dp[x][y][2] != -1) return dp[x][y][2];

    dp[x][y][2] = arriba(x - 1, y);

    return dp[x][y][2];
}

bool abajo(int x, int y){
    if(x < 0 || y < 0 || x >= filas || y >= columnas) return false;

    if(matriz[x][y] == true) dp[x][y][3] = true;
    if(dp[x][y][3] != -1) return dp[x][y][3];

    dp[x][y][3] = abajo(x + 1, y);

    return dp[x][y][3];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, sol = 0;
    memset(dp, -1, sizeof(dp));

    cin >> filas >> columnas;

    matriz.resize(filas);

    for(int i = 0; i < filas; i ++){
        matriz[i].resize(columnas);

        for(int j = 0; j < columnas; j ++){
            cin >> a;
            matriz[i][j] = a;
        }
    }

    for(int i = 0; i < filas; i ++){
        for(int j = 0; j < columnas; j ++){
            if(matriz[i][j] == false) sol += arriba(i, j) + abajo(i, j) + izquierda(i, j) + derecha(i, j);
        }
    }

    cout << sol;

    return 0;
}