#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int nodos, destino, e;

    cin >> nodos >> destino;

    vector<vector<int> > matriz(nodos + 1);
    vector<int> cola;
    vector<bool> visitado(nodos + 1);
    queue<int> colatrue;

    for(int i = 1; i <= nodos; i ++){
        cin >> e;

        if(e == 1){
            for(int j = 0; j < cola.size(); j ++){
                matriz[cola[j]].push_back(i);
            }
            cola.push_back(i);
        }
    }

    cola.clear();

    for(int i = 1; i <= nodos; i ++){
        cin >> e;

        if(e == 1){
            for(int j = 0; j < cola.size(); j ++){
                matriz[i].push_back(cola[j]);
            }
            cola.push_back(i);
        }
    }

    visitado[1] = true;
    colatrue.push(1);

    while(!colatrue.empty()){
        int actual = colatrue.front();
        colatrue.pop();

        if(actual == destino) break;

        for(int i = 0; i < matriz[actual].size(); i ++){
            int ady = matriz[actual][i];

            if(visitado[ady] == false){
                visitado[ady] = true;
                colatrue.push(ady);
            }
        }
    }

    if(visitado[destino] == true) cout << "YES";
    else cout << "NO";

    return 0;
}