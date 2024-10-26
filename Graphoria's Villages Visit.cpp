#include <bits/stdc++.h>

using namespace std;

long long nodos;
long long dp[1000005], sol, cant, a, b;
vector<long long> matriz[1000005];

void dfs(long long actual, long long padre){
    dp[actual] = 1;

    for(auto i: matriz[actual]){
        if(i == padre) continue;

        dfs(i, actual);
        dp[actual] += dp[i];
    }

    if(dp[actual] * (nodos - dp[actual]) > sol){
        sol = dp[actual] * (nodos - dp[actual]);
        cant = 1;
    }
    else if(dp[actual] * (nodos - dp[actual]) == sol){
        cant ++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> nodos;

    for(long long i = 1; i < nodos; i ++){
        cin >> a >> b;

        matriz[a].push_back(b);
        matriz[b].push_back(a);
    }

    dfs(1, 0);

    cout << sol << " " << cant;

    return 0;
}