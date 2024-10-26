#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cantidad, querys;

    cin >> cantidad;

    vector<long long> lista1(cantidad + 1);
    vector<long long> lista2(cantidad + 1);

    for(int i = 1; i <= cantidad; i ++){
        cin >> lista1[i];

        lista2[i] = lista1[i];

        lista1[i] += lista1[i - 1];
    }

    sort(lista2.begin(), lista2.end());

    for(int i = 1; i <= cantidad; i ++){
        lista2[i] += lista2[i - 1];
    }

    cin >> querys;

    for(int i = 0; i < querys; i ++){
        int a, b, c;

        cin >> c >> a >> b;

        if(c == 1) cout << lista1[b] - lista1[a - 1] << "\n";
        else cout << lista2[b] - lista2[a - 1] << "\n";
    }

    return 0;
}