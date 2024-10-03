#include <bits/stdc++.h>

using namespace std;

long long dp[105][100005];
const long long MOD = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, m;

    cin >> n >> m;

    vector<long long> lista(n + 1);

    cin >> lista[1];
    if(lista[1] == 0){
        for(long long i = 1; i <= m; i ++){
            dp[i][1] = 1;
        }
    }
    else{
        dp[lista[1]][1] = 1;
    }

    for(long long i = 2; i <= n; i ++){
        cin >> lista[i];

        if(lista[i] == 0){
            for(long long j = 1; j <= m; j ++){
                dp[j][i] = dp[j][i - 1] + dp[j - 1][i - 1] + dp[j + 1][i - 1];
                dp[j][i] %= MOD;
            }
        }
        else{
            dp[lista[i]][i] = dp[lista[i]][i - 1] + dp[lista[i] - 1][i - 1] + dp[lista[i] + 1][i - 1];
            dp[lista[i]][i] %= MOD;
        }
    }

    if(lista[n] == 0){
        long long sum = 0;

        for(long long i = 1; i <= m; i ++){
            sum += dp[i][n];
            sum %= MOD;
        }

        cout << sum;

        return 0;
    }
    cout << dp[lista[n]][n];

    return 0;
}