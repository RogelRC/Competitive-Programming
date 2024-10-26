#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, sol, e1, e2;
    string cadena;

    cin >> casos;

    while(casos --){
        sol = 10;

        cin >> cadena;

        e1 = e2 = 0;
        for(int i = 0; i < 10; i ++){
            if(i % 2 == 0){
                if(cadena[i] == '?')e1 += 1;
                else e1 += cadena[i] - '0';;
            }
            else if(cadena[i] != '?')e2 += cadena[i] - '0';

            if(e1 - e2 > (10 - i) / 2){
                sol = min(sol, i + 1);
                break;
            }
        }

        e1 = e2 = 0;
        for(int i = 0; i < 10; i ++){
            if(i % 2 == 1){
                if(cadena[i] == '?')e2 += 1;
                else e2 += cadena[i] - '0';;
            }
            else if(cadena[i] != '?')e1 += cadena[i] - '0';

            if(e2 - e1 > (9 - i) / 2){
                sol = min(sol, i + 1);
                break;
            }
        }

        cout << sol << "\n";
    }

    return 0;
}