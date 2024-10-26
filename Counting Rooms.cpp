#include <bits/stdc++.h>
 
using namespace std;
 
int filas, columnas, sol;
int adx[4] = {0, 0, 1, -1};
int ady[4] = {1, -1, 0, 0};
vector<vector<char> > matriz;
 
void DFS(int x, int y){
    int xx, yy;
 
    for(int i = 0; i < 4; i ++){
        xx = x + adx[i];
        yy = y + ady[i];
 
        if(xx >= 0 && xx < filas && yy >= 0 && yy < columnas && matriz[xx][yy] == '.'){
            matriz[xx][yy] = '#';
 
            DFS(xx, yy);
        }
    }
}
 
int main(){
 
    cin >> filas >> columnas;
 
    matriz.resize(filas);
 
    for(int i = 0; i < filas; i ++){
        matriz[i].resize(columnas);
 
        for(int j = 0; j < columnas; j ++){
            cin >> matriz[i][j];
        }
    }
 
    for(int i = 0; i < filas; i ++){
        for(int j = 0; j < columnas; j ++){
            if(matriz[i][j] == '.'){
                sol ++;
                matriz[i][j] = '#';
 
                DFS(i, j);
            }
        }
    }
 
    cout << sol;
 
    return 0;
}