#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<char> > matriz;
 
void printPath(int x, int y){
    if(matriz[x][y] == 'A')return;
 
    if(matriz[x][y] == 'U')printPath(x + 1, y);
    else if(matriz[x][y] == 'D')printPath(x - 1, y);
    else if(matriz[x][y] == 'R')printPath(x, y - 1);
    else if(matriz[x][y] == 'L')printPath(x, y + 1);
 
    cout << matriz[x][y];
}
 
int main(){
    int filas, columnas, inix, finx, iniy, finy;
    int adyx[4] = {0, 0, 1, -1};
    int adyy[4] = {1, -1, 0, 0};
 
    cin >> filas >> columnas;
 
    matriz.resize(filas);
    vector<vector<int> > visitado(filas);
    queue<pair<int, int> > cola;
 
    for(int i = 0; i < filas; i ++){
        matriz[i].resize(columnas);
        visitado[i].resize(columnas);
 
        for(int j = 0; j < columnas; j ++){
            cin >> matriz[i][j];
            visitado[i][j] = -1;
 
            if(matriz[i][j] == 'A'){
                inix = i;
                iniy = j;
            }
 
            else if(matriz[i][j] == 'B'){
                finx = i;
                finy = j;
            }
        }
    }
 
    cola.push({inix, iniy});
    visitado[inix][iniy] = 0;
 
    while(!cola.empty()){
        pair<int, int> actual = cola.front();
        if(actual.first == finx && actual.second == finy)break;;
 
        cola.pop();
 
        for(int i = 0; i < 4; i ++){
            int x = actual.first + adyx[i];
            int y = actual.second + adyy[i];
 
            if(x >= 0 && x < filas && y >= 0 && y < columnas && matriz[x][y] != '#' && visitado[x][y] == -1){
                visitado[x][y] = visitado[actual.first][actual.second] + 1;
                cola.push({x, y});
 
                if(i == 0)matriz[x][y] = 'R';
                else if(i == 1)matriz[x][y] = 'L';
                else if(i == 2)matriz[x][y] = 'D';
                else matriz[x][y] = 'U';
            }
        }
    }
 
    if(visitado[finx][finy] != -1){
        cout << "YES\n";
        cout << visitado[finx][finy] << "\n";
        printPath(finx, finy);
    }
 
    else cout << "NO\n";
 
    return 0;
}