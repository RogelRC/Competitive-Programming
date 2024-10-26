#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, cantidad, n;
    int dp[100005][2];

    cin >> casos;

    while(casos --){
        memset(dp, 0, sizeof(dp));

        cin >> cantidad;

        for(int i = 0; i < cantidad; i ++){
            cin >> n;
            
            dp[n][(i + 1) % 2] = dp[n][i % 2] + 1;
        }

        for(int i = 1; i <= cantidad; i ++){
            cout << max(dp[i][0], dp[i][1]) << " ";
        }
        cout << "\n";
    }

    return 0;
}