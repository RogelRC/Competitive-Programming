#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100005
int n;
vector<vector<int> > lista(2);
long long memo[2][MAX_N];

long long sol(int fila, int columna) {
    if (columna == n) return 0;
    if (memo[fila][columna] != -1) return memo[fila][columna];

    long long res = sol(fila, columna + 1);
    res = max(res, lista[fila][columna] + sol(1 - fila, columna + 1));

    return memo[fila][columna] = res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    lista[0].resize(n);
    lista[1].resize(n);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> lista[i][j];
        }
    }

    memset(memo, -1, sizeof(memo));

    cout << max(sol(0, 0), sol(1, 0)) << "\n";

    return 0;
}