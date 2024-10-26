#include <bits/stdc++.h>

using namespace std;

int rest, a, b;
int restriccion[15][15];

int convertir(int i, int j){
    return i * 3 + j + 1;
}

pair<int, int> convertir(int n){
    return {(n - 1) / 3, (n - 1) % 3};
}

int solve(vector<vector<char>> &matriz, bool turno){

    if(matriz[0][0] != '-' && matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2]){
        return matriz[0][0] == 'x' ? 1: -1;
    }
    else if(matriz[0][2] != '-' && matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0]){
        return matriz[0][2] == 'x' ? 1: -1;
    }
    else{
        for(int i = 0; i < 3; i ++){
            if(matriz[0][i] != '-' && matriz[0][i] == matriz[1][i] && matriz[0][i] == matriz[2][i]){
                return matriz[0][i] == 'x' ? 1: -1;
            }
            else if(matriz[i][0] != '-' && matriz[i][0] == matriz[i][1] && matriz[i][0] == matriz[i][2]){
                return matriz[i][0] == 'x' ? 1: -1;
            }
        }
    }

    bool tie = true;
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            if(matriz[i][j] == '-') tie = false;
        }
    }
    if(tie == true) return 0;

    int sol = (turno == 0 ? INT_MAX: INT_MIN);
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            if(matriz[i][j] != '-') continue;

            bool puedo = true;
            int c = convertir(i, j);

            for(int k = 1; k <= 9; k ++){
                pair<int, int> par = convertir(k);
                if(restriccion[k][c] == true && matriz[par.first][par.second] == '-'){
                    puedo = false;
                    break;
                }
            }

            if(puedo == true){
                if(turno == 0){
                    matriz[i][j] = 'o';
                    sol = min(sol, solve(matriz, 1));
                }
                else{
                    matriz[i][j] = 'x';
                    sol = max(sol, solve(matriz, 0));
                }
                matriz[i][j] = '-';
            }
        }
    }

    return (sol == INT_MAX || sol == INT_MIN ? 0: sol);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> rest;

    for(int i = 0; i < rest; i ++){
        cin >> a >> b;

        restriccion[a][b] = true;
    }

    vector<vector<char>> matriz(3, vector<char>(3));

    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            matriz[i][j] = '-';
        }
    }

    int s = solve(matriz, 1);

    //cout << s << "\n\n";
    if(s == -1) cout << "O";
    else if(s == 1) cout << "X";
    else cout << "E";

    return 0;
}