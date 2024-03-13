#include <bits/stdc++.h>
#define min3(a, b, c) min(a, min(b, c))

using namespace std;

int n, memo[205][205][205];
vector<int> lista, copia;
map<int, int> mapa;

int backtracking(int p, int a, int b){
    if(p == n) return 0;

    if(memo[p][a][b] != -1) return memo[p][a][b];

    if(lista[p] > a && lista[p] < b){
        memo[p][a][b] = min3(1 + backtracking(p + 1, a, b), backtracking(p + 1, lista[p], b), backtracking(p + 1, a, lista[p]));
        return memo[p][a][b];
    }
    if(lista[p] > a){
        memo[p][a][b] = min(1 + backtracking(p + 1, a, b), backtracking(p + 1, lista[p], b));
        return memo[p][a][b];
    }
    if(lista[p] < b){
        memo[p][a][b] = min(1 + backtracking(p + 1, a, b), backtracking(p + 1, a, lista[p]));
        return memo[p][a][b];
    }

    memo[p][a][b] = 1 + backtracking(p + 1, a, b);
    return memo[p][a][b];
}

void solve(){
    lista.clear();
    copia.clear();
    mapa.clear();
    memset(memo, -1, sizeof(memo));

    lista.resize(n);
    copia.resize(n);
    int cont = 1;

    for(int i = 0; i < n; i ++){
        cin >> lista[i];

        copia[i] = lista[i];
    }

    sort(copia.begin(), copia.end());

    for(int i = 0; i < n; i ++){
        if(mapa[copia[i]] == 0){
            mapa[copia[i]] = cont;
            cont ++;
        }
    }

    for(int i = 0; i < n; i ++){
        lista[i] = mapa[lista[i]];
    }

    cout << backtracking(0, 0, 201) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n && n != -1){
        solve();
    }

    return 0;
}