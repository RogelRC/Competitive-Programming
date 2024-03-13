#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, cantidad;
    bool dp[5005];
    vector<int> lista;
    bool flag;

    cin >> casos;

    while(casos --){
        cin >> cantidad;

        memset(dp, 0, sizeof(dp));
        flag = true;
        lista.resize(cantidad);

        for(int i = 0; i < cantidad; i ++){
            cin >> lista[i];
        }

        sort(lista.begin(), lista.end());

        if(lista[0] != 1){
            cout << "NO\n";
            continue;
        }

        dp[1] = true;

        for(int i = 1; i < cantidad; i ++){
            if(dp[lista[i]] == false){
                flag = false;
                break;
            }

            for(int j = 5005; j >= lista[i]; j --){
                dp[j] = max(dp[j], dp[j - lista[i]]);
            }
        }

        if(flag == true)cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}