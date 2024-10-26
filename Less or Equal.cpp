#include <bits/stdc++.h>

using namespace std;

/*
1 3 3 5 7 10 20
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, cont = 0, sol = -1;

    cin >> n >> k;

    vector<int> lista(n);

    for(int i = 0; i < n; i ++){
        cin >> lista[i];
    }

    sort(lista.begin(), lista.end());

    for(int i = 0; i < n; i ++){
        if(cont < k) cont++;

        for(int j = i + 1; j < n; j ++){
            if(lista[j] == lista[i]){
                cont ++;
                i = j;
            }
            else break;
        }

        if(cont == k){
            sol = lista[i];
            break;
        }
        else if(cont > k) break;
    }

    if(k == 0){
        if(lista[0] == 1) cout << -1;
        else cout << 1;
    }
    else cout << sol;

    return 0;
}
