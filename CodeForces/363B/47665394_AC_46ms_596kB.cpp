#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cantidad, rango, sol = INT_MAX, pos;

    cin >> cantidad >> rango;

    vector<int> ta(cantidad + 1);

    for(int i = 1; i <= cantidad; i ++){
        cin >> ta[i];

        ta[i] += ta[i - 1];
    }

    for(int i = rango; i <= cantidad; i ++){
        if(sol > ta[i] - ta[i - rango]){
            sol = ta[i] - ta[i - rango];
            pos = i - rango + 1;
        }
    }

    cout << pos << "\n";
}