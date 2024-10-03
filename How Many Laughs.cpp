#include <bits/stdc++.h>

using namespace std;

map<int, bool> criba;
int n, p, sol;
vector<int> lista;
bool b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;

    lista.resize(n);

    for(int i = 0; i < n; i ++){
        cin >> lista[i];

        if(lista[i] == 1) b = true;
    }

    if(b == true){
        cout << p;
        return 0;
    }

    sort(lista.begin(), lista.end());

    for(int i = 0; i < lista.size(); i ++){
        int num = lista[i];

        if(criba[num] == true) continue;

        for(int j = num; j <= p; j += num){
            criba[j] = true;
        }
    }

    for(auto i: criba){
        if(i.second == true) sol ++;
    }

    cout << sol;

    return 0;
}