#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cantidad, ant, n, sol = 1, sum = 1;

    cin >> cantidad;

    cin >> ant;
    
    cantidad --;
    while(cantidad --){
        cin >> n;

        if(n <= ant * 2){
            sum ++;
            sol = max(sol, sum);
        }
        else sum = 1;

        ant = n;
    }

    cout << sol << "\n";

    return 0;
}