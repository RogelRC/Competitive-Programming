#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int filas, querys, y1, x2, y2, x1;
    char c;

    cin >> filas >> querys;

    vector<vector<int> > matriz(filas + 1, vector<int>(filas + 1));

    for(int i = 1; i <= filas; i ++){
        for(int j = 1; j <= filas; j ++){
            cin >> c;

            if(c == '*') matriz[i][j] = 1;
            else matriz[i][j] = 0;

            matriz[i][j] += matriz[i - 1][j] + matriz[i][j - 1] - matriz[i - 1][j - 1];

            //cout << matriz[i][j] << " ";
        }
        //cout << "\n";
    }

    while(querys --){
        cin >> y1 >> x1 >> y2 >> x2;

        cout << matriz[y2][x2] - matriz[y1 - 1][x2] - matriz[y2][x1 - 1] + matriz[y1 - 1][x1 - 1] << "\n";
    }

    return 0;
}