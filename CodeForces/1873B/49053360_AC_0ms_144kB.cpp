#include <bits/stdc++.h>

using namespace std;

int solve(){
    int n, sol = INT_MIN, aux; 

    cin >> n;

    vector<int> lista(n);

    for(int i = 0; i < n; i ++){
        cin >> lista[i];
    }

    for(int i = 0; i < n; i ++){
        aux = 1;

        for(int j = 0; j < n; j ++){
            if(j == i) aux *= lista[j] + 1;
            else aux *= lista[j];
        }

        sol = max(sol, aux);
    }

    return sol;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos;

    cin >> casos;

    while(casos --){
        cout << solve() << "\n";
    }

    return 0;
}