#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long nodos, aristas, k, e1, e2, p;
    vector<pair<long long, long long>> matriz[100005];
    long long distancia[100005];
    long long cont[100005];
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> cola;

    cin >> nodos >> aristas >> k;

    while(aristas --){
        cin >> e1 >> e2 >> p;

        matriz[e1].push_back({e2, p});
    }

    cola.push({0, 1});

    while(!cola.empty()){
        long long actual = cola.top().second;
        long long peso = cola.top().first;

        cola.pop();

        cont[actual] ++;
        
        if(actual == nodos){
            cout << peso << " ";
            if(cont[actual] == k) return 0;
        }

        if(cont[actual] > k) continue;

        for(auto i: matriz[actual]){
            distancia[i.first] = peso + i.second;

            cola.push({distancia[i.first], i.first});
        }
    }

    return 0;
}