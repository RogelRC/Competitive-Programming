#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cantidad, a, b, last;
    queue<int> cola;

    cin >> cantidad;

    vector<vector<int> > matriz(cantidad + 1);
    vector<int> visitado(cantidad + 1, -1);

    for(int i = 1; i < cantidad; i ++){
        cin >> a >> b;

        matriz[a].push_back(b);
        matriz[b].push_back(a);
    }

    cola.push(1);
    visitado[1] = 0;

    while(!cola.empty()){
        int actual = cola.front();
        cola.pop();

        last = actual;

        for(auto i: matriz[actual]){
            if(visitado[i] == -1){
                visitado[i] = visitado[actual] + 1;
                cola.push(i);
            }
        }
    }

    fill(visitado.begin(), visitado.end(), -1);
    cola.push(last);
    visitado[last] = 0;

    while(!cola.empty()){
        int actual = cola.front();
        cola.pop();

        last = actual;

        for(auto i: matriz[actual]){
            if(visitado[i] == -1){
                visitado[i] = visitado[actual] + 1;
                cola.push(i);
            }
        }
    }

    cout << visitado[last];

    return 0;
}