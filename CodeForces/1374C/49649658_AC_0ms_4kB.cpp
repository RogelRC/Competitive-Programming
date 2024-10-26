#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, n, sol, m;
    char c;

    cin >> casos;

    while(casos --){
        m = 0;
        sol = 0;

        cin >> n;

        while(n --){
            cin >> c;

            if(c == '(') m ++;
            else m --;

            if(m < 0) sol = max(sol, m * -1);
        }

        cout << sol << "\n";
    }

    return 0;
}