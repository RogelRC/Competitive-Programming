#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cantidad, poder, awake, sol = 0;

    cin >> cantidad >> poder;

    vector<int> ta1(cantidad + 1);
    vector<int> ta2(cantidad + 2);

    for(int i = 1; i <= cantidad; i ++){
        cin >> ta1[i];

        ta2[i] = ta1[i];
        ta2[i] += ta2[i - 1];
    }
    for(int i = 1; i <= cantidad; i ++){
        cin >> awake;

        if(awake == 0){
            ta1[i] = 0;
        }

        ta1[i] += ta1[i - 1];
    }

    for(int i = poder; i <= cantidad; i ++){
        sol = max(sol, (ta2[i] - ta2[i - poder]) - (ta1[i] - ta1[i - poder]));
    }

    cout << ta1[cantidad] + sol;

    return 0;
}