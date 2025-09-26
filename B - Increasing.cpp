#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int casos;

    cin >> casos;

    while(casos --){
        int cantidad;

        cin >> cantidad;

        vector<int> numeros(cantidad);

        for(int i = 0; i < cantidad; i ++){
            cin >> numeros[i];
        }

        sort(numeros.begin(), numeros.end());

        string resultado = "YES";

        for(int i = 1; i < cantidad; i ++){
            if(numeros[i] == numeros[i - 1]){
                resultado = "NO";
                break;
            }
        }

        cout << resultado << "\n";
    }
}