#include <bits/stdc++.h>

using namespace std;

int cantidad;
vector<int> lista;
int dp[55][105];

int dina(int p, int ant){
    if(p >= cantidad) return 0;
    if(lista[p] - ant > 1 || lista[p] - ant < 0) return 0;

    if(dp[p][ant] != -1) return dp[p][ant];

    if(lista[p] - ant == 0) dp[p][ant] = max(1 + dina(p + 1, lista[p] + 1), dina(p + 1, lista[p]));
    else dp[p][ant] = 1 + dina(p + 1, lista[p]);

    return dp[p][ant];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, sol;

    cin >> casos;

    while(casos --){
        sol = 1;
        memset(dp, -1, sizeof(dp));

        cin >> cantidad;

        lista.resize(cantidad);

        for(int i = 0; i < cantidad; i ++){
            cin >> lista[i];
        }

        for(int i = 1; i < cantidad; i ++){
            sol = max(sol, 1 + max(dina(i, lista[i - 1]), dina(i, lista[i - 1] + 1)));
        }

        cout << sol << "\n";
    }

    return 0;
}