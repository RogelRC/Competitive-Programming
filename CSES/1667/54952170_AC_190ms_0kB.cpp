#include <bits/stdc++.h>
 
using namespace std;
 
int nodos, aristas;
vector<int> visitado;
vector<vector<int> >matriz;
vector<int> distancia;
 
void printWay(int n){
    if(visitado[n] != n){
        printWay(visitado[n]);
    }
 
    cout << n << " ";
}
 
int main(){
    int e1, e2;
 
    cin >> nodos >> aristas;
 
    visitado.resize(nodos + 1);
    matriz.resize(nodos + 1);
    distancia.resize(nodos + 1);
 
    fill(visitado.begin(), visitado.end(), -1);
    fill(distancia.begin(), distancia.end(), 1);
 
    for(int i = 0; i < aristas; i ++){
        cin >> e1 >> e2;
 
        matriz[e1].push_back(e2);
        matriz[e2].push_back(e1);
    }
 
    queue<int> cola;
 
    cola.push(1);
    visitado[1] = 1;
 
    while(!cola.empty()){
        int actual = cola.front();
        cola.pop();
 
        for(int i = 0; i < matriz[actual].size(); i ++){
            int ady = matriz[actual][i];
 
            if(visitado[ady] == -1){
                visitado[ady] = actual;
                distancia[ady] = distancia[actual] + 1;
 
                cola.push(ady);
            }
        }
    }
    if(visitado[nodos] != -1){
        cout << distancia[nodos] << "\n";
        printWay(nodos);
    }
 
    else{
        cout << "IMPOSSIBLE";
    }
    return 0;
}