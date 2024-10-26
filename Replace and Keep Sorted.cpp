#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cant, q, k, e1, e2, sol;

    cin >> cant >> q >> k;

    vector<int> lista(cant + 1);
    vector<int> ta(cant + 1);

    for(int i = 1; i <= cant; i ++){
        cin >> lista[i];
    }

    for(int i = 1; i < cant; i ++){
        ta[i] = ta[i - 1] + ((lista[i] - lista[i - 1] - 1) + (lista[i + 1] - lista[i] - 1));

        //cout << ta[i] << " ";
    }
    ta[cant] = ta[cant - 1] + (lista[cant] - lista[cant - 1] - 1);
    //cout << ta[cant] << "\n";

    while(q --){
        cin >> e1 >> e2;

        sol = ta[e2] - ta[e1 - 1];

        if(e2 == cant) sol += (k - lista[e2]);
        else sol += (k - lista[e2 + 1] + 1);

        if(e1 != 1) sol += lista[e1 - 1];

        cout << sol << "\n";
    }

    return 0;
}