#include <bits/stdc++.h>

using namespace std;

vector<pair<int, string> > lista;
int dp[1005][2][2][2];

int dina(int p, bool arr[3]){
    if(p == lista.size()){
        if(arr[0] == true && arr[1] == true && arr[2] == true){
            return 0;
        }
        else return 20000000;
    }

    if(dp[p][arr[0]][arr[1]][arr[2]] != -1) return dp[p][arr[0]][arr[1]][arr[2]];

    bool asd[3];
    asd[0] = arr[0];
    asd[1] = arr[1];
    asd[2] = arr[2];

    for(int i = 0; i < lista[p].second.size(); i ++){
        asd[lista[p].second[i] - 'A'] = true;
    }

    dp[p][arr[0]][arr[1]][arr[2]] = min(lista[p].first + dina(p + 1, asd), dina(p + 1, arr));

    return dp[p][arr[0]][arr[1]][arr[2]];

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cantidad;
    bool a[3];
    a[0] = a[1] = a[2] = false;

    cin >> cantidad;

    lista.resize(cantidad);

    for(int i = 0; i < cantidad; i ++){
        cin >> lista[i].first >> lista[i].second;
    }

    memset(dp, -1, sizeof(dp));

    int sol = dina(0, a);

    if(sol >= 20000000) cout << -1;
    else cout << sol;

    return 0;
}