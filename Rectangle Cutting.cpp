#include <bits/stdc++.h>
 
using namespace std;
 
int dp[505][505];
 
int solve(int a, int b){
    if(a == b) return 0;
 
    if(dp[a][b] != INT_MAX) return dp[a][b];
    if(dp[b][a] != INT_MAX) return dp[b][a];
 
    for(int i = 1; i < a; i ++){
        dp[a][b] = dp[b][a] = min(dp[a][b], 1 + solve(i, b) + solve(a - i, b));
    }
    for(int i = 1; i < b; i ++){
        dp[a][b] = dp[b][a] = min(dp[a][b], 1 + solve(a, i) + solve(a, b - i));
    }
 
    return dp[a][b];
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int a, b;
 
    for(int i = 0; i <= 500; i ++){
        for(int j = 0; j <= 500; j ++){
            dp[i][j] = INT_MAX;
        }
    }
 
    cin >> a >> b;
 
    cout << solve(a, b);
 
    return 0;
}