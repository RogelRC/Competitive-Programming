#include <bits/stdc++.h>

using namespace std;

short btc, cantidad;
vector<short> lista;
short dp[101][2][101];

short dina(short p, short pares, short impares, short precio){
    if(precio > btc) return INT16_MIN;
    
    if(p == cantidad){
        if(pares == 0 && impares == 0) return -1;
        else if(pares == impares) return 0;
        else return INT16_MIN;
    }

    bool b = false;
    if(pares == impares && pares > 0) b = true;

    if(dp[p][b][precio] != -1) return dp[p][b][precio];

    short costo = abs(lista[p] - lista[p + 1]);

    if(lista[p] % 2 == 0) pares ++;
    else impares ++;

    dp[p][b][precio] = dina(p + 1, pares, impares, precio);

    if(pares == impares && pares > 0) dp[p][b][precio] = max(dp[p][b][precio], short(1 + dina(p + 1, 0, 0, precio + costo)));

    return dp[p][b][precio];

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> cantidad >> btc;

    lista.resize(cantidad + 1);

    for(short i = 0; i < cantidad; i ++){
        cin >> lista[i];
    }
    lista[cantidad] = lista[cantidad - 1];

    cout << dina(0, 0, 0, 0);

    return 0;
}