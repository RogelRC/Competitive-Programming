#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, n, m, k, ant, actual;
    bool flag;

    cin >> casos;

    while(casos --){
        flag = true;

        cin >> n >> m >> k;

        cin >> ant;

        for(int i = 1; i < n; i ++){
            cin >> actual;

            m += ant - max(actual - k, 0);

            if(m < 0) flag = false;

            ant = actual;
        }

        if(flag == false) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}