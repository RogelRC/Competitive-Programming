#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, arr[4], sol;
    string cadena;

    cin >> casos;

    while(casos --){
        arr[1] = arr[2] = arr[3] = -1;
        sol = INT_MAX;

        cin >> cadena;

        for(int i = 0; i < cadena.size(); i ++){
            if(cadena[i] == '1' && arr[2] != -1 && arr[3] != -1){
                sol = min(sol, i - min(arr[2], arr[3]) + 1);
            }
            else if(cadena[i] == '2' && arr[1] != -1 && arr[3] != -1){
                sol = min(sol, i - min(arr[1], arr[3]) + 1);
            }
            else if(cadena[i] == '3' && arr[1] != -1 && arr[2] != -1){
                sol = min(sol, i - min(arr[1], arr[2]) + 1);
            }

            arr[cadena[i] - '0'] = i;
        }

        if(sol != INT_MAX) cout << sol << "\n";
        else cout << "0\n";
    }

    return 0;
}