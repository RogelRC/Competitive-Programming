#include <bits/stdc++.h>
 
using namespace std;

#define MOD 1000000007
 
int nodos, aristas, e1, e2;
vector<int> matriz[100005];
int memo[100005];
 
int dfs(int actual){
    if(actual == 1){
        return 1;
    }
 
    if(memo[actual] != -1) return memo[actual];
 
    int aux = 0;
 
    for(auto &i: matriz[actual]){
        aux += dfs(i);
        aux %= MOD;
    }
 
    return memo[actual] = aux;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> nodos >> aristas;

    for(int i = 1; i <= nodos; i ++){
        memo[i] = -1;
    }
 
    while(aristas --){
        cin >> e1 >> e2;
 
        matriz[e2].push_back(e1);
    }
 
 
    dfs(nodos);

    cout << memo[nodos];
 
    return 0;
}