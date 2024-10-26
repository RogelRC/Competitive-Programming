#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int nodos, aristas, e1, e2, p, visitados = 0;
    vector<pair<int, int>> matriz[100005];
    bool visitado[100005];
    long long distancia[100005];
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long,int>>> cola;

    cin >> nodos >> aristas;

    for(long long i = 1; i <= nodos; i ++){
        distancia[i] = INT64_MAX;
    }

    while(aristas --){
        cin >> e1 >> e2 >> p;

        matriz[e1].push_back({e2, p});
    }

    cola.push({0, 1});
    distancia[1] = 0;

    while(!cola.empty()){
        long long actual = cola.top().second;
        cola.pop();

        if(visitado[actual] == true) continue;
        //cout << actual << "\n";
        visitado[actual] = true;

        if(visitados == nodos) break;

        for(auto i: matriz[actual]){
            if(distancia[i.first] > distancia[actual] + i.second){
                distancia[i.first] = distancia[actual] + i.second;
                cola.push({distancia[i.first], i.first});
            }
        }
    }

    for(long long i = 1; i <= nodos; i ++){
        cout << distancia[i] << " ";
    }

    return 0;
}