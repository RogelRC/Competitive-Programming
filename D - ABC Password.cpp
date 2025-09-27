#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int dp[1005][1005];

int dina(int abren, int cierran){
    if(abren < 0 || cierran < 0) return 0;
    if(abren == 0 && cierran == 0) return 1;

    if(dp[abren][cierran] != -1) return dp[abren][cierran] % mod;

    if(abren == cierran) return dp[abren][cierran] = dina(abren - 1, cierran) % mod;

    return dp[abren][cierran] = (dina(abren - 1, cierran) + dina(abren, cierran - 1)) % mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));

    int casos;

    cin >> casos;

    while(casos --){
        int n;

        cin >> n;

        cout << dina(n, n) % mod << "\n";
    }
}