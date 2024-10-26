#include <bits/stdc++.h>

using namespace std;

long long tabla[200005];
int cantidad, querys, a, b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> cantidad >> querys;

    for(int i = 1; i <= cantidad; i ++){
        cin >> tabla[i];
        tabla[i] += tabla[i - 1];
    }

    while(querys --){
        cin >> a >> b;

        cout << tabla[b] - tabla[a - 1] << "\n";
    }

    return 0;
}