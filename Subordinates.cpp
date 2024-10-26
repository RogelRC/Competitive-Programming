#include <bits/stdc++.h>
 
using namespace std;
 
int nodos, n;
vector<int> matriz[200005];
int hijos[200005];
 
int dfs(int nodo){
    int sum = 0;
 
    for(auto i: matriz[nodo]){
        sum += 1 + dfs(i);
    }
 
    return hijos[nodo] = sum;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> nodos;
 
    for(int i = 2; i <= nodos; i ++){
        cin >> n;
 
        matriz[n].push_back(i);
    }
 
    dfs(1);
 
    for(int i = 1; i <= nodos; i ++){
        cout << hijos[i] << " ";
    }
 
    return 0;
}