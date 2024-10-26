#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int m, d;
    const int MOD = pow(10, 9) + 7;
 
    cin >> m >> d;
 
    vector<int> monedas(m);
    vector<int> dp(d + 1);
    dp[0] = 1;
 
    for (int i = 0; i < m; i++)
    {
        cin >> monedas[i];
    }
 
    for (int j = 0; j < m; j++)
    {
        for (int i = 1; i <= d; i++)
        {
            if (i - monedas[j] >= 0)
            {
                dp[i] += dp[i - monedas[j]];
                dp[i] %= MOD;
            }
        }
    }
 
    cout << dp[d];
 
    return 0;
}