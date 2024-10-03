#include <bits/stdc++.h>

using namespace std;

int arr[30];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string candena;
    int unos = 0, sol = 0;

    cin >> candena;

    for(int i = 0; i < candena.size(); i ++){
        arr[candena[i] - 'a'] ++;
    }

    for(int i = 0; i < 30; i ++){
        sol += arr[i];

        if(arr[i] % 2 == 1){
            unos ++;
        }
    }

    if(unos > 1){
        cout << sol - unos + 1;
    }
    else cout << sol;

    return 0;
}