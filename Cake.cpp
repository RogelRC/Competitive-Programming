#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cantidad, sum = 0, sol = 0;

    cin >> cantidad;

    vector<int> lista(cantidad);

    for(int i = 0; i < cantidad; i ++){
        cin >> lista[i];
    }

    sort(lista.begin(), lista.end());

    for(int i = 0; i < cantidad; i ++){
        if(lista[i] > sum){
            sol ++;
            sum += lista[i];
        }
    }

    cout << sol;

    return 0;
}