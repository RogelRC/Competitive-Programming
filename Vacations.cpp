#include <bits/stdc++.h>
#define min3(a, b, c) min(a, min(b, c))

using namespace std;

int n;
vector<int> lista;
int memo[105][5];

int Ba(int p, int anterior){
    if(p == n) return 0;

    if(memo[p][anterior] != -1) return memo[p][anterior];

    if(lista[p] == 0){
        memo[p][anterior] = 1 + Ba(p + 1, 0);

        return memo[p][anterior];
    }

    if(lista[p] == 1){
        if(anterior == 1) memo[p][anterior] = 1 + Ba(p + 1, 0);
        else memo[p][anterior] = min(1 + Ba(p + 1, 0), Ba(p + 1, 1));

        return memo[p][anterior];
    }

    if(lista[p] == 2){
        if(anterior == 2) memo[p][anterior] = 1 + Ba(p + 1, 0);
        else memo[p][anterior] = min(1 + Ba(p + 1, 0), Ba(p + 1, 2));

        return memo[p][anterior];
    }

    if(lista[p] == 3){
        if(anterior == 0) memo[p][anterior] = min3(1 + Ba(p + 1, 0), Ba(p + 1, 1), Ba(p + 1, 2));
        else if(anterior == 1) memo[p][anterior] = min(1 + Ba(p + 1, 0), Ba(p + 1, 2));
        else if(anterior == 2) memo[p][anterior] = min(1 + Ba(p + 1, 0), Ba(p + 1, 1));

        return memo[p][anterior];
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    lista.resize(n);
    memset(memo, -1, sizeof(memo));

    for(int i = 0; i < n; i ++){
        cin >> lista[i];
    }

    cout << Ba(0, 0);

    return 0;
}