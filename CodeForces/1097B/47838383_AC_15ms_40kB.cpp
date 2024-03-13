#include <bits/stdc++.h>

using namespace std;

int dp[20][365];
vector<int> lista;

bool dina(int p, int sum){
    sum %= 360;

    if(p == lista.size()){
        if(sum == 0) return true;
        return false;
    }

    if(dp[p][sum] != -1) return dp[p][sum];

    dp[p][sum] = max(dina(p + 1, sum + lista[p]), dina(p + 1, sum + 360 - lista[p]));

    return dp[p][sum];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cantidad;
    memset(dp, -1, sizeof(dp));

    cin >> cantidad;
    lista.resize(cantidad);

    for(int i = 0; i < cantidad; i ++){
        cin >> lista[i];
    }

    if(dina(0, 0) == true) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}