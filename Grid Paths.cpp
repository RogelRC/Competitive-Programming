#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int N, dp[1005][1005];
    const int MOD = pow(10, 9) + 7;
    char matriz[1005][1005];
 
    dp[1][1] = 1;
 
    cin >> N;
 
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> matriz[i][j];
        }
    }
 
    if(matriz[1][1] == '*'){
        cout << 0;
        return 0;
    }
 
    for(int i = 1; i <= N; i ++){
        for(int j = 1; j <= N; j ++){
            if(matriz[i][j] == '*') continue;
 
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
 
            dp[i][j] %= MOD;
        }
    }
 
    cout << dp[N][N];
 
    return 0;
}