#include <bits/stdc++.h>

using namespace std;

void solve(){
    int cantidad, largo, oper = 0;

    cin >> cantidad >> largo;

    vector<char> lista(cantidad);

    for(int i = 0; i < cantidad; i ++){
        cin >> lista[i];
    }

    for(int i = 0; i < cantidad; i ++){
        if(lista[i] == 'B'){
            oper ++;
            i += largo - 1;
        }
    }

    cout << oper << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos;

    cin >> casos;

    while(casos --){
        solve();
    }

    return 0;
}