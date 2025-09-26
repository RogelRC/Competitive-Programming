#include <bits/stdc++.h>

using namespace std;

void solve(){
    vector<vector<char>> matriz(8, vector<char>(8));

    for(int i = 0; i < 8; i ++){
        for(int j = 0; j < 8; j ++){
            cin >> matriz[i][j];
        }
    }

    char sol = '.';

    for(int i = 0; i < 8; i ++){        
        if(matriz[i][0] != '.' && matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][2] == matriz[i][3] && matriz[i][3] == matriz[i][4] && matriz[i][4] == matriz[i][5] && matriz[i][5] == matriz[i][6] && matriz[i][6] == matriz[i][7]){
            sol = matriz[i][0];
            break;
        }

        else if(matriz[0][i] != '.' && matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i] && matriz[2][i] == matriz[3][i] && matriz[3][i] == matriz[4][i] && matriz[4][i] == matriz[5][i] && matriz[5][i] == matriz[6][i] && matriz[6][i] == matriz[7][i]){
            sol = matriz[0][i];
            break;
        }
    }

    cout << sol << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int casos;

    cin >> casos;

    while(casos --){
        solve();
    }
}