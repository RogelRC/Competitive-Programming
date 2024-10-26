#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    long long nodos, aristas, e1, e2, p, sol = 0, total = 0;
    vector<pair<long long, long long>> matriz[100005];
    bool visitado[100005];
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long ,long long>>> cola;
 
    cin >> nodos >> aristas;
 
    for(long long i = 0; i <= nodos; i ++){
        visitado[i] = false;
    }
 
    while(aristas --){
        cin >> e1 >> e2 >> p;
 
        matriz[e1].push_back({e2, p});
        matriz[e2].push_back({e1, p});
    }
 
    cola.push({0, 1});
 
    while(!cola.empty()){
        long long actual = cola.top().second;
        long long peso = cola.top().first;
 
        cola.pop();
 
        if(visitado[actual] == true) continue;
        visitado[actual] = true;
        total ++;
 
        sol += peso;
 
        for(auto i: matriz[actual]){
            if(visitado[i.first] == false){
                cola.push({i.second, i.first});
            }
        }
    }
 
    if(total == nodos) cout << sol;
    else cout << "IMPOSSIBLE";
 
    return 0;
}