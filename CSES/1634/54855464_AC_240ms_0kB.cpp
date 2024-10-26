#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX / 2

int dp[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cantidad, suma;

    cin >> cantidad >> suma;

    vector<int> lista(cantidad);

    for(int i = 0; i <= suma; i ++){
        dp[i] = INF;
    }

    for(int i = 0; i < cantidad; i ++){
        cin >> lista[i];

        dp[lista[i]] = 1;
    }

    for(int i = 1; i<= suma; i ++){
        for(auto j: lista){
            if(i >= j){
                dp[i] = min(dp[i], 1 + dp[i - j]);
            }
        }
    }

    if(dp[suma] == INF) cout << -1;
    else cout << dp[suma];

    return 0;
}