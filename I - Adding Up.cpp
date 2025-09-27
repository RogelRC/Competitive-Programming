#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int cantidad, suma, dp[255][255];

int dina(int c, int sum){
    if(c < 0) return 0;
    if(sum < 0) return 0;
    if(c == 0 && sum == 0) return 1;

    if(dp[c][sum] != -1) return dp[c][sum] % mod;
    dp[c][sum] = 0;

    for(int i = 0; i <= suma; i ++){
        dp[c][sum] = (dp[c][sum] + dina(c - 1, sum - i)) % mod;
    }

    return dp[c][sum] % mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));

    int casos;

    cin >> casos;

    while(casos --){
        cin >> suma >> cantidad;

        cout << dina(cantidad, suma) % mod << "\n";
    }
}