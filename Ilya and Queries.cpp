#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string cadena;

    cin >> cadena;

    vector<int> ta(cadena.size() + 1);

    ta[0] = 0;

    for(int i = 1; i < cadena.size(); i++){
        if(cadena[i] == cadena[i - 1]){
            ta[i + 1]++;
        }

        ta[i + 1] += ta[i];
    }

    int queries;

    cin >> queries;
    
    while(queries--){
        int a, b;

        cin >> a >> b;

        cout << ta[b] - ta[a] << "\n";
    }

    return 0;
}