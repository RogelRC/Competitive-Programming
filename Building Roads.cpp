#include <bits/stdc++.h>
 
using namespace std;
 
int nodos, aristas;
vector<vector<int> > matriz;
vector<bool> visitado;
 
void DFS(int x){
    for(int i = 0; i < matriz[x].size(); i ++){
        int ad = matriz[x][i];
 
        if(visitado[ad] == false){
            visitado[ad] = true;
 
            DFS(ad);
        }
    }
}
 
int main(){
 
    int e1, e2, s = 0;
    vector<int> sol;
 
    cin >> nodos >> aristas;
 
    matriz.resize(nodos + 1);
    visitado.resize(nodos + 1);
 
    fill(visitado.begin(), visitado.end(), false);
 
    while (aristas --){
        cin >> e1 >> e2;
 
        matriz[e1].push_back(e2);
        matriz[e2].push_back(e1);
    }
    
    for(int i = 1; i <= nodos; i ++){
        if(visitado[i] == false){
            sol.push_back(i);
            s ++;
 
            DFS(i);
        }
    }
 
    cout << s - 1 << "\n";
    for(int i = 0; i < sol.size() - 1; i ++){
        cout << sol[i] << " " << sol[i + 1] << "\n";
    }
 
    return 0;
}