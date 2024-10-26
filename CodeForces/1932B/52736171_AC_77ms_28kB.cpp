#include <bits/stdc++.h>

using namespace std;

int mm(int a, int b) {
    if (a % b == 0) {
        return a + b;
    }

    int m = ((a / b) + 1) * b;
    return m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, n, sol;
    vector<int> lista;

    cin >> casos;

    while(casos --){
        cin >> n;

        lista.resize(n);

        for(int i = 0; i < n; i ++){
            cin >> lista[i];
        }

        sol = lista[0];

        for(int i = 1; i < n; i ++){
            sol = mm(sol, lista[i]);
        }

        cout << sol << "\n";
    }

    return 0;
}
