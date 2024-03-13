#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos;
    string cadena;

    cin >> casos;

    while(casos --){
        cin >> cadena;

        if(cadena.size() > 10)cout << cadena[0] << cadena.size() - 2 << cadena[cadena.size() - 1] << "\n";
        else cout << cadena << "\n";
    }

    return 0;
}