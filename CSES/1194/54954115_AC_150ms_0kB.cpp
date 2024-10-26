#include <bits/stdc++.h>

using namespace std;

struct datos{
    int x, y;
    char c;
};

vector<vector<char>> recorrido;
vector<char> sol;
void printRecorrido(int x, int y){
    if(recorrido[x][y] == 'X') return;

    if(recorrido[x][y] == 'U') printRecorrido(x + 1, y);
    else if(recorrido[x][y] == 'D') printRecorrido(x - 1, y);
    else if(recorrido[x][y] == 'L') printRecorrido(x, y + 1);
    else if(recorrido[x][y] == 'R') printRecorrido(x, y - 1);

    sol.push_back(recorrido[x][y]);

    //cout << "ASD: " << x << " " << y << "\n";
}

int main(){
    /*
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    */

    int filas, columnas;
    int adyx[4] = {0, 0, 1, -1};
    int adyy[4] = {-1, 1, 0, 0};
    char c;
    queue<datos> cola;

    cin >> filas >> columnas;

    vector<vector<bool>> matriz(filas);
    vector<vector<char>> matrizchar(filas);
    recorrido.resize(filas);

    for(int i = 0; i < filas; i ++){
        matriz[i].resize(columnas, false);
        matrizchar[i].resize(columnas);
        recorrido[i].resize(columnas, 'X');

        for(int j = 0; j < columnas; j ++){
            cin >> matrizchar[i][j];

            if(matrizchar[i][j] == 'M'){
                cola.push({i, j, 'M'});
                matriz[i][j] = true;
            }
            else if(matrizchar[i][j] == '#'){
                matriz[i][j] = true;
            }
        }
    }

    for(int i = 0; i < filas; i ++){
        for(int j = 0; j < columnas; j ++){
            if(matrizchar[i][j] == 'A'){
                cola.push({i, j, 'A'});
                matriz[i][j] = true;
            }
        }
    }

    while(cola.empty() == false){
        int x = cola.front().x;
        int y = cola.front().y;
        char tipo = cola.front().c;

        //cout << "|| " << x << " " << y << " " << tipo << "\n";

        cola.pop();

        for(int i = 0; i < 4; i ++){
            int xx = x + adyx[i];
            int yy = y + adyy[i];

            if(xx >= 0 && xx < filas && yy >= 0 && yy < columnas){
                //cout << "--> " << xx << " " << yy << " " << matriz[xx][yy] << "\n";

                if(matriz[xx][yy] == false){
                    if(tipo == 'A'){
                        char r;

                        if(xx == x + 1) r = 'D';
                        else if(xx == x - 1) r = 'U';
                        else if(yy == y + 1) r = 'R';
                        else r = 'L';

                        //cout << "R: " << xx << " " << yy << "\n";
                        recorrido[xx][yy] = r;
                    }
                    cola.push({xx, yy, tipo});
                    matriz[xx][yy] = true;
                }
            }
            else if(tipo == 'A'){
                printRecorrido(x, y);
                cout << "YES\n" << sol.size() << "\n";
                for(auto i: sol){
                    cout << i;
                }
                return 0;
            }
        }
    }

    cout << "NO";

    return 0;
}