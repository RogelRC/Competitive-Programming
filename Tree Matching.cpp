#include <bits/stdc++.h>
 
using namespace std;
 
int nodos, sol, a, b;
vector<int> matriz[200005];
int visitado[200005];
 
void dfs(int actual, int anterior){
    for(auto i: matriz[actual]){
        if(i == anterior) continue;
 
        dfs(i, actual);
    }
 
    if(anterior != -1 && visitado[actual] == false && visitado[anterior] == false){
        visitado[actual] = visitado[anterior] = true;
        //cout << actual << " " << anterior << "\n";
        sol ++;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> nodos;
 
    for(int i = 1; i < nodos; i ++){
        cin >> a >> b;
 
        matriz[a].push_back(b);
        matriz[b].push_back(a);
    }
 
    dfs(1, -1);
 
    cout << sol;
 
    return 0;
}