#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, cantidad;
    char c;
    bool matriz[55][55];

    cin >> casos;

    salto:
    while(casos --){
        cin >> cantidad;

        for(int i = 0; i < cantidad; i ++){
            for(int j = 0; j < cantidad; j ++){
                cin >> c;

                matriz[i][j] = c - '0';
            }
        }

        for(int i = 0; i < cantidad; i ++){
            for(int j = 0; j < cantidad; j ++){
                if(matriz[i][j] == true){

                    if(i + 1 < cantidad && j + 1 < cantidad && matriz[i + 1][j] != true && matriz[i][j + 1] != true){
                        cout << "NO\n";

                        goto salto;
                    }
                }
            }
        }

        cout << "YES\n";
    }

    return 0;
}