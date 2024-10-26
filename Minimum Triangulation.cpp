#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, sol = 0;

    cin >> n;

    for(int i = 2; i < n; i ++){
        sol += i * (i + 1);
    }

    cout << sol;

    return 0;
}