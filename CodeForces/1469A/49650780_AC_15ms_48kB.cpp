#include <bits/stdc++.h>

using namespace std;

char lista[105];
int memo[105][105];
int n;

bool dp(int p, int sum){
    if(sum < 0) return false;
    if(p == n){
        if(sum == 0) return true;
        return false;
    }

    if(memo[p][sum] != -1) return memo[p][sum];

    if(lista[p] == '(') return memo[p][sum] = dp(p + 1, sum + 1);
    else if(lista[p] == ')') return memo[p][sum] = dp(p + 1, sum - 1);

    else return memo[p][sum] = dp(p + 1, sum - 1) || dp(p + 1, sum + 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos;
    string cadena;

    cin >> casos;

    while(casos --){
        cin >> cadena;

        n = cadena.size();

        for(int i = 0; i <= n; i ++){
            for(int j = 0; j <= n; j ++){
                memo[i][j] = -1;
            }
        }

        for(int i = 0; i < n; i ++){
            lista[i] = cadena[i];
        }

        if(dp(0, 0)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}