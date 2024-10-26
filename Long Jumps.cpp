#include <bits/stdc++.h>

using namespace std;

vector<int> numeros;
vector<int> dp(2 * pow(10, 5) + 5);

int cantidad;

int ba(int pos){
    if(pos >= cantidad)return 0;

    if(dp[pos] != -1)return dp[pos];

    dp[pos] = numeros[pos] + ba(pos + numeros[pos]);

    return dp[pos];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, sol;
    cin >> casos;

    while(casos --){
        cin >> cantidad;

        sol = INT_MIN;

        numeros.resize(cantidad);
        fill(dp.begin(), dp.end(), -1);

        for(int i = 0; i < cantidad; i ++){
            cin >> numeros[i];
        }

        for(int i = 0; i < cantidad; i ++){
            sol = max(sol, ba(i));
        }

        cout << sol << "\n";
    }

    return 0;
}