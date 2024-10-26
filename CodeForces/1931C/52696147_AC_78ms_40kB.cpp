#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, n, ei, ed, cei, ced;
    bool fei, fed;
    vector<int> lista;

    cin >> casos;

    while(casos --){
        cin >> n;

        lista.resize(n);

        for(int i = 0; i < n; i ++){
            cin >> lista[i];
        }

        ei = lista[0];
        ed = lista[n - 1];

        cei = ced = 1;
        fei = fed = true;

        for(int i = 1; i < n && (fei || fed); i ++){
            if(lista[i] == ei && fei == true) cei ++;
            else fei = false;

            if(lista[n - i - 1] == ed && fed == true) ced ++;
            else fed = false;
        }

        if(ei == ed) cout << max(n - cei - ced, 0) << "\n";
        else cout << n - max(cei, ced) << "\n";
    }

    return 0;
}
