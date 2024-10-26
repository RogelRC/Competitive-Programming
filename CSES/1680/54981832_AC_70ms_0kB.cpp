#include <bits/stdc++.h>
 
using namespace std;
 
int nodos, aristas, e1, e2;
bool vis = false;
vector<int> matriz[100005];
int memo[100005];
int padre[100005];
 
int dfs(int actual){
    if(actual == nodos){
        vis = true;
        return 0;
    }
 
    if(memo[actual] != -1) return memo[actual];
 
    int s = INT_MIN, aux;
 
    for(auto &i: matriz[actual]){
        aux = 1 + dfs(i);

        //cout << "Esto: " << actual << " ---> " << i << ": " << aux << "\n";
        if(aux > s){
            //cout << "Entrada: " << actual << " ---> " << i << ": " << aux << "\n\n";
            //cout << "P: " << i << " " << actual << "\n";
            s = aux;
            padre[actual] = i;
        }
    }
 
    return memo[actual] = s;
}
 
void ruta(int actual){
    if(padre[actual] == -1){
        cout << actual << " ";
        return;
    }
 
    cout << actual << " ";
    ruta(padre[actual]);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> nodos >> aristas;
 
    for(int i = 0; i <= nodos; i ++){
        padre[i] = memo[i] = -1;
    }
 
    while(aristas --){
        cin >> e1 >> e2;
 
        matriz[e1].push_back(e2);
    }
 
 
    int sol = dfs(1);
 
    if(vis == true){
        cout << 1 + sol << "\n";
        ruta(1);
    }
    else cout << "IMPOSSIBLE";

    /*
    cout << "\n";
    for(int i = 1; i <= nodos; i ++){
        cout << padre[i] << " ";
    }
    */
 
    return 0;
}