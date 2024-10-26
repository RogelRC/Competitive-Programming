#include <bits/stdc++.h>

using namespace std;

int N, sol;
vector<int> lista;

void Criba(){
    for(int i = 2; i <= N; i ++){
        if(lista[i] > 0) continue;

        for(int j = i; j<= N; j += i){
            lista[j] ++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    lista.resize(N + 1);

    Criba();

    for(int i = 1; i <= N; i ++){
        if(lista[i] == 2) sol ++;
    }

    cout << sol;

    return 0;
}