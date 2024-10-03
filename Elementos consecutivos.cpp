#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cantidad, sol = 0, ant = -999, nmax = 0;

    cin >> cantidad;

    vector<int> lista(cantidad);

    for(int i = 0; i < cantidad; i ++){
        cin >> lista[i];
    }

    sort(lista.begin(), lista.end());
    unique(lista.begin(),lista.end());
    
    for(int i = 0; i < lista.size(); i ++){
        if(lista[i] == ant + 1) nmax ++;
        else nmax = 1;

        ant = lista[i];

        sol = max(sol, nmax);
    }

    cout << sol;

    return 0;
}