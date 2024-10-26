#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int nodos, a, b, maslejano;
    vector<int> matriz[200005];
    queue<int> cola;
    int visitado[200005];
 
    memset(visitado, -1, sizeof(visitado));
 
    cin >> nodos;
 
    for(int i = 1; i < nodos; i ++){
        cin >> a >> b;
 
        matriz[a].push_back(b);
        matriz[b].push_back(a);
    }
 
    cola.push(1);
    visitado[1] = 0;
 
    while(!cola.empty()){
        int actual = cola.front();
        cola.pop();
 
        maslejano = actual;
 
        for(auto i: matriz[actual]){
            if(visitado[i] == -1){
                visitado[i] = visitado[actual] + 1;
                cola.push(i);
            }
        }
    }
 
    memset(visitado, -1, sizeof(visitado));
 
    cola.push(maslejano);
    visitado[maslejano] = 0;
 
    while(!cola.empty()){
        int actual = cola.front();
        cola.pop();
 
        maslejano = visitado[actual];
 
        for(auto i: matriz[actual]){
            if(visitado[i] == -1){
                visitado[i] = visitado[actual] + 1;
                cola.push(i);
            }
        }
    }
 
    cout << maslejano;
 
    return 0;
}