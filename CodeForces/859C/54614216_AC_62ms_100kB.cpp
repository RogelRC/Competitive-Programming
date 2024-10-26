#include <bits/stdc++.h>

using namespace std;

int cantidad, sum1, sum2;
int memo[55];
int camino[55];
vector<int> lista;

int cero(int a, int b){
    if(abs(a) < abs(b)) return a;
    return b;
}

int sol(int p){
    if(p == cantidad) return 0;

    if(memo[p] != -1) return memo[p];

    int xx = lista[p] + sol(p + 1);
    int yy = lista[p] * (-1) + sol(p + 1);

    if(abs(xx) < abs(yy)) camino[p] = 1;
    else camino[p] = -1;

    return memo[p] = cero(xx, yy);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(memo, -1, sizeof(memo));

    cin >> cantidad;

    lista.resize(cantidad);

    for(int i = 0; i < cantidad; i ++){
        cin >> lista[i];
    }

    int kk = sol(0);

    for(int i = 0; i < cantidad; i ++){
        if(lista[i] * camino[i] > 0) sum1 += lista[i] * camino[i];
        else sum2 += lista[i] * camino[i];
    }

    sum1 = abs(sum1);
    sum2 = abs(sum2);

    if(sum1 > sum2) swap(sum1, sum2);

    cout << sum1 << " " << sum2;

    return 0;
}