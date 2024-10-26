#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tabla[2], casos;
    string cadena;

    cin >> casos;

    while(casos --){
        tabla[0] = tabla[1] = 0;

        cin >> cadena;

        for(int i = 0; i < cadena.size(); i ++){
            tabla[cadena[i] - 'A'] ++;
        }

        if(tabla[0] > tabla[1]) cout << "A\n";
        else cout << "B\n";
    }

    return 0;
}