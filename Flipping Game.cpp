#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cantidad, sol = 0;
    bool uno = true;
    
    cin >> cantidad;

    vector<int> lista(cantidad + 1);

    for(int i = 1; i <= cantidad; i ++){
        cin >> lista[i];

        if(lista[i] != 1){
            uno = false;
        }

        lista[i] += lista[i - 1];
    }

    if(uno == false){
        for(int i = 1; i <= cantidad; i ++){
            for(int j = i; j <= cantidad; j ++){
                sol = max(sol, j - i + 1 - (lista[j] - lista[i - 1]) - (lista[j] - lista[i - 1]));
            }
        }
        cout << sol + lista[cantidad];
    }
    else{
        cout << cantidad - 1;
    }


    return 0;
}