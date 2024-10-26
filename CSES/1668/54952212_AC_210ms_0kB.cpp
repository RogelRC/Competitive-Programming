#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int> > matriz;
vector<int> team;
 
bool flag = true;
 
void DFS(int actual){
 
    for(int i = 0; i < matriz[actual].size(); i ++){
        if(team[matriz[actual][i]] == -1){
            team[matriz[actual][i]] = 3 - team[actual];
 
            DFS(matriz[actual][i]);
        }
 
        else if(team[actual] == team[matriz[actual][i]]){
            flag = false;
            return;
        }
    }
}
 
int main(){
    int nodos, aristas, e1, e2;
 
    cin >> nodos >> aristas;
 
    matriz.resize(nodos + 1);
    team.resize(nodos + 1);
 
    fill(team.begin(), team.end(), -1);
 
    for(int i = 0; i < aristas; i ++){
        cin >> e1 >> e2;
 
        matriz[e1].push_back(e2);
        matriz[e2].push_back(e1);
    }
 
    for(int i = 1; i <= nodos; i ++){
        if(team[i] == -1){
            team[i] = 1;
            DFS(i);
        }
    }
 
    if(flag == true){
        for(int i = 1; i <= nodos; i ++){
            cout << team[i] << " ";
        }
    }
 
    else cout << "IMPOSSIBLE";
 
    return 0;
}