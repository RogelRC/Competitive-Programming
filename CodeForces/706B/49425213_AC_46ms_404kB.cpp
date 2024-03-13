#include <bits/stdc++.h>

using namespace std;

int ta[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cantidad, precio;

    cin >> cantidad;

    while(cantidad --){
        cin >> precio;
        ta[precio] ++;
    }


    for(int i = 1; i <= 100000; i ++){
        ta[i] += ta[i - 1];
    }

    cin >> cantidad;

    while(cantidad --){
        cin >> precio;

        precio = min(precio, 100000);

        cout << ta[precio] << "\n";
    }

    return 0;
}