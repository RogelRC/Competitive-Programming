#include <bits/stdc++.h>
using namespace std;

int filas, columnas;
int matriz[1005][1005];
int dp1[1005][1005], dp2[1005][1005], dp3[1005][1005], dp4[1005][1005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> filas >> columnas;
    for (int i = 1; i <= filas; ++i) {
        for (int j = 1; j <= columnas; ++j) {
            cin >> matriz[i][j];
        }
    }

    for (int i = 1; i <= filas; ++i) {
        for (int j = 1; j <= columnas; ++j) {
            dp1[i][j] = matriz[i][j];
            if (i > 1) dp1[i][j] += dp1[i-1][j];
            if (j > 1) dp1[i][j] = max(dp1[i][j], matriz[i][j] + dp1[i][j-1]);
        }
    }

    for (int i = filas; i >= 1; --i) {
        for (int j = columnas; j >= 1; --j) {
            dp2[i][j] = matriz[i][j];
            if (i < filas) dp2[i][j] += dp2[i+1][j];
            if (j < columnas) dp2[i][j] = max(dp2[i][j], matriz[i][j] + dp2[i][j+1]);
        }
    }

    for (int i = filas; i >= 1; --i) {
        for (int j = 1; j <= columnas; ++j) {
            dp3[i][j] = matriz[i][j];
            if (i < filas) dp3[i][j] += dp3[i+1][j];
            if (j > 1) dp3[i][j] = max(dp3[i][j], matriz[i][j] + dp3[i][j-1]);
        }
    }

    for (int i = 1; i <= filas; ++i) {
        for (int j = columnas; j >= 1; --j) {
            dp4[i][j] = matriz[i][j];
            if (i > 1) dp4[i][j] += dp4[i-1][j];
            if (j < columnas) dp4[i][j] = max(dp4[i][j], matriz[i][j] + dp4[i][j+1]);
        }
    }

    int sol = 0;

    for (int i = 2; i < filas; ++i) {
        for (int j = 2; j < columnas; ++j) {
            int opt1 = dp1[i-1][j] + dp2[i+1][j] + dp3[i][j-1] + dp4[i][j+1];
            int opt2 = dp1[i][j-1] + dp2[i][j+1] + dp3[i+1][j] + dp4[i-1][j];
            sol = max(sol, max(opt1, opt2));
        }
    }

    cout << sol << "\n";
    return 0;
}