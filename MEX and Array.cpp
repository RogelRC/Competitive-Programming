#include <bits/stdc++.h>

using namespace std;

vector<int> lista;
int dp[105][105][105];

int r;
int dina(int p, int l){
    if(p > r){
        int aux = -1;
        vector<int> loco;

        for(int i = l; i <= r; i ++){
            loco.push_back(lista[i]);
        }
        sort(loco.begin(), loco.end());

        for(int i = 0; i < loco.size(); i ++){
            if(i != loco[i]){
                aux = i;
                break;
            }   
        }
        if(aux == -1)aux = loco.size();
        if(l == p)aux --;

        return aux;
    }

    if(dp[p][l][r] != -1)return dp[p][l][r];

    int aux = -1;
    vector<int> loco;

    for(int i = l; i <= p; i ++){
        loco.push_back(lista[i]);
    }
    sort(loco.begin(), loco.end());

    for(int i = 0; i < loco.size(); i ++){
        if(i != loco[i]){
            aux = i;
            break;
        }
    }
    if(aux == -1)aux = loco.size();

    dp[p][l][r] = max(1 + aux + dina(p + 1, p + 1), dina (p + 1, l));
    return dp[p][l][r];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, cantidad, sum;

    cin >> casos;

    while(casos --){
        cin >> cantidad;

        lista.resize(cantidad);
        memset(dp, -1, sizeof(dp));
        sum = 0;

        for(int i = 0; i < cantidad; i ++){
            cin >> lista[i];
        }

        for(int i = 0; i < cantidad; i ++){
            for(int j = 0; j + i < cantidad; j ++){
                r = i + j;

                sum += dina(j, j) + 1;
            }
        }

        cout << sum << "\n";

    }

    return 0;
}