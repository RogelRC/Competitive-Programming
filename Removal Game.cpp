#include <bits/stdc++.h>
 
using namespace std;
 
long long n;
vector<long long> lista;
long long dp[5005][5005][2];
 
long long solve(long long a, long long b, bool turno){
    if(a > b) return 0;
 
    if(dp[a][b][turno] != INT64_MIN) return dp[a][b][turno];
 
    if(turno == true){
        return dp[a][b][turno] = max(lista[a] + solve(a + 1, b, !turno), lista[b] + solve(a, b - 1, !turno));
    }
    else{
        return dp[a][b][turno] = min(solve(a + 1, b, !turno), solve(a, b - 1, !turno));
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    for(long long i = 0; i < 5005; i ++){
        for(long long j = 0; j < 5005; j ++){
            for(long long k = 0; k < 2; k ++){
                dp[i][j][k] = INT64_MIN;
            }
        }
    }
 
    cin >> n;
 
    lista.resize(n);
 
    for(long long i = 0; i < n; i ++){
        cin >> lista[i];
    }
 
    cout << solve(0, n - 1, true);
 
    return 0;
}