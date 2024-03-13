#include <bits/stdc++.h>

using namespace std;

int a, b, c;
int dp[4005];

int dina(int n){
    if(n == 0) return 0;
    else if(n < 0) return INT_MIN;

    if(dp[n] != -1) return dp[n];

    dp[n] = 1 + max(dina(n - a), max(dina(n - b), dina(n - c)));

    return dp[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    memset(dp, -1, sizeof(dp));

    cin >> n >> a >> b >> c;

    cout << dina(n);

    return 0;
}