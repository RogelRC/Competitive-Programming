#include <bits/stdc++.h>

using namespace std;

vector<int> lista;
vector<bool> tapado;

int dp[200005][2];

int dina(int p, bool estado){
    if(p >= lista.size()) return 0;

    else if(dp[p][estado] != -1)return dp[p][estado];

    else if(p == 0 && tapado[p] == true) dp[p][estado] = lista[p] + dina(p + 1, true);

    else if(p == 0) dp[p][estado] = dina(p + 1, false);

    else if(p > 0 && estado == false && tapado[p] == true){
        dp[p][estado] = max(lista[p - 1] + dina(p + 1, false), lista[p] + dina(p + 1, true));
    }

    else if(p > 0 && estado == true && tapado[p] == true){
        dp[p][estado] = lista[p] + dina(p + 1, true);
    }

    else dp[p][estado] = dina(p + 1, false);

    return dp[p][estado];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, cantidad;
    char c;

    cin >> casos;

    while(casos --){
        for(int i = 0; i < 200005; i ++){
            dp[i][0] = -1;
            dp[i][1] = -1;
        }

        cin >> cantidad;

        lista.resize(cantidad);
        tapado.resize(cantidad);

        for(int i = 0; i < cantidad; i ++){
            cin >> c;

            if(c == '0')tapado[i] = false;
            else tapado[i] = true;
        }

        for(int i = 0; i < cantidad; i ++){
            cin >> lista[i];
        }

        cout << dina(0, 0) << "\n";
    }

    return 0;
}