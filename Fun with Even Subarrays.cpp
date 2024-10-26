#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, cantidad, tengo, cambios;

    vector<int> lista;

    cin >> casos;

    while(casos--){
        cin >> cantidad;

        lista.resize(cantidad);

        tengo = 1;
        cambios = 0;

        for(int i = cantidad - 1; i >= 0; i --){
            cin >> lista[i];
        }

        for(int i = 1; i < cantidad;){
            if(lista[i] != lista[0]){
                cambios ++;
                i += tengo;

                tengo *= 2;
            }

            else{
                tengo ++;
                i ++;
            }
        }

        cout << cambios << "\n";


    }

    return 0;
}