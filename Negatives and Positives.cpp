#include <bits/stdc++.h>
#define LLMIN INT64_MIN

using namespace std;

long long asd(long long n){
    if(n == -1)return 0;
    return 1;
}

vector<long long> lista;
long long dp[200005][2];

long long dina(long long p, long long estado){
    if(p >= lista.size()) return 0;

    if(dp[p][asd(estado)] != LLMIN)return dp[p][asd(estado)];

    long long actual = estado * lista[p];

    if(p < lista.size() - 1)dp[p][asd(estado)] = max(actual + dina(p + 1, 1), actual * -1 + dina(p + 1, -1));

    else dp[p][asd(estado)] = actual + dina(p + 1, 1);

    return dp[p][asd(estado)];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long casos, cantidad, sol;

    cin >> casos;

    while(casos --){
        sol = LLMIN;

        cin >> cantidad;

        lista.resize(cantidad);
        for(long long i = 0; i <= cantidad; i ++){
            dp[i][0] = LLMIN;
            dp[i][1] = LLMIN;
        }

        for(long long i = 0; i < cantidad; i ++){
            cin >> lista[i];
        }

        sol = max(lista[0] + dina(1, 1), lista[0] * -1 + dina(1, -1));

        cout << sol << "\n";
    }

    return 0;
}