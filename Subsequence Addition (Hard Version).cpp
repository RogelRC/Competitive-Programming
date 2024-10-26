#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long casos, cantidad, sum;
    bool flag;
    vector<long long> lista;

    cin >> casos;

    while(casos --){
        sum = 1;
        flag = true;

        cin >> cantidad;

        lista.resize(cantidad);

        for(long long i = 0; i < cantidad; i ++){
            cin >> lista[i];
        }

        sort(lista.begin(), lista.end());

        if(lista[0] != 1){
            cout << "NO\n";
            continue;
        }

        for(long long i = 1; i < cantidad; i ++){
            if(lista[i] > sum){
                flag = false;
                break;;
            }

            sum += lista[i];
        }

        if(flag == true)cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}