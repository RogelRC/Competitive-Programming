#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cantidad, x;
    priority_queue<pair<int, int>> cola;

    cin >> cantidad >> x;

    vector<int> lista(cantidad);

    for(int i = 0; i < cantidad; i ++){
        cin >> lista[i];

        cola.push({lista[i], i});
    }

    while(!cola.empty()){
        int p = cola.top().second;
        cola.pop();

        if(p > 0){
            if(lista[p] - lista[p - 1] > x){
                lista[p - 1] = lista[p] - x;
                cola.push({lista[p - 1], p - 1});
            }
        }
        if(p < cantidad - 1){
            if(lista[p] - lista[p + 1] > x){
                lista[p + 1] = lista[p] - x;
                cola.push({lista[p + 1], p + 1});
            }
        }
    }

    for(int &i: lista){
        cout << i << " ";
    }
}