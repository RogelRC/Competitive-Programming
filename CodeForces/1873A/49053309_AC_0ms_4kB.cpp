#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos;
    string cadena;

    cin >> casos;

    while(casos --){
        cin >> cadena;

        if(cadena[0] == 'a' || cadena[1] == 'b' || cadena[2] == 'c') cout << "YES\n";

        else cout << "NO\n";
    }


    return 0;
}