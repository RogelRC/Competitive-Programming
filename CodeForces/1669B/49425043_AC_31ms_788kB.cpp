#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arreglo[200005], n, casos, a, sol;

    cin >> casos;

    while(casos --){
        sol = -1;

        cin >> n;

        for(int i = 0; i <= n; i ++){
            arreglo[i] = 0;
        }

        for(int i = 0; i < n; i ++){
            cin >> a;

            arreglo[a] ++;
            if(arreglo[a] >= 3) sol = a;
        }

        cout << sol << "\n";
    }

    return 0;
}