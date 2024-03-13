#include <bits/stdc++.h>

using namespace std;

int dp[1000][1000];

int dina(int a, int b){
    if(a <= 0 || b <= 0) return 0;
    if(a == 1 && b == 1) return 0;

    if(dp[a][b] != -1)return dp[a][b];

    if(a == 1) dp[a][b] = dp[b][a] = 1 + dina(a + 1, b - 2);
    else if(b == 1) dp[a][b] = dp[b][a] = 1 + dina(a - 2, b + 1);

    else dp[a][b] = dp[b][a] = 1 + max(dina(a + 1, b - 2), dina(a - 2, b + 1));

    return dp[a][b];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 1000; i ++){
        for(int j = 0; j < 1000; j ++){
            dp[i][j] = -1;
        }
    }

    int x, y;

    cin >> x >> y;

    cout << dina(x, y);

    return 0;
}