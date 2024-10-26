#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, cantidad, sol = 0, nmax;
    vector<int> lista;

    cin >> casos;

    while(casos --){
        cin >> cantidad;

        lista.resize(cantidad);
        sol = 0;

        for(int i = 0; i < cantidad; i ++){
            cin >> lista[i];
        }

        sort(lista.begin(), lista.end());

        int i = 0;

        while(i < cantidad){
            nmax = lista[i];

            for(int j = 1; j < nmax; j ++){


                if(j + i > cantidad) break;

                nmax = max(nmax, lista[j + i]);
            }

            i += nmax;

            if(i <= cantidad) sol++;
        }

        cout << sol << "\n";
    }

    return 0;
}