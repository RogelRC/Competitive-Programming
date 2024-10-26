#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, n, a, sol;

    cin >> casos;

    while(casos --){
        cin >> n;

        sol = 0;

        for(int i = 0; i < n; i ++){
            cin >> a;

            sol ^= a;
        }

        if(sol != 0) cout << "first\n";
        else cout << "second\n";
    }

    return 0;
}