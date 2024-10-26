#include <bits/stdc++.h>
 
using namespace std;
 
long long n, total;
long long memo[505][125550];
const long long MOD = 1000000007;
 
long long dp(long long p, long long sum){
    if(p == n + 1){
        if(total - sum == sum) return 1;
        else return 0;
    }
 
    if(memo[p][sum] != -1) return memo[p][sum] % MOD;
 
    return memo[p][sum] = (dp(p + 1, sum) % MOD + dp(p + 1, sum + p) % MOD) % MOD;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    memset(memo, -1, sizeof(memo));
 
    cin >> n;
 
    total = (n * (n + 1)) / 2;
 
    cout << (dp(1, 0) * 500000004) % MOD << "\n";
 
    return 0;
}