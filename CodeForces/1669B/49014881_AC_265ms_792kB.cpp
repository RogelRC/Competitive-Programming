#include <bits/stdc++.h>

using namespace std;

int main(){

    int casos, cantidad, sol;
    vector<int> lista;

    cin >> casos;

    while(casos --){
        sol = -1;

        cin >> cantidad;

        lista.resize(cantidad);

        for(int i = 0; i < cantidad; i ++){
            cin >> lista[i];
        }

        sort(lista.begin(), lista.end());

        for(int i = 0; i < cantidad - 2; i ++){
            if(lista[i] == lista[i + 1] && lista[i] == lista[i + 2]){
                sol = lista[i];
                break;
            }
        }

        cout << sol << "\n";
    }

    return 0;
}
