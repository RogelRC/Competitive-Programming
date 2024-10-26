#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cantidad, letras, cant = 0;
    long long sol = 0;
    char c;

    cin >> cantidad >> letras;

    vector<char> lista(cantidad);
    bool arr[30];

    memset(arr, 0, sizeof(arr));

    for(int i = 0; i < cantidad; i ++){
        cin >> lista[i];
    }

    for(int i = 0; i < letras; i ++){
        cin >> c;
        arr[c - 'a'] = true;
    }

    for(int i = 0; i < cantidad; i ++){
        if(arr[lista[i] - 'a'] == false) cant = 0;
        else{
            cant ++;
            sol += cant;
        }
    }

    cout << sol;

    return 0;
}