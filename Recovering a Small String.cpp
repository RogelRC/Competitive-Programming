#include <bits/stdc++.h>

using namespace std;

char func(int a){
    return char(a + 96);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, n, temp, asd;
    string sol;

    cin >> casos;

    while(casos --){
        sol.clear();

        cin >> n;

        temp = max(2, n - 26);
        asd = n - temp;
        n = temp;

        sol.push_back(func(asd));

        temp = max(1, n - 26);
        asd = n - temp;
        n = temp;

        sol.push_back(func(asd));
        sol.push_back(func(n));

        for(int i = 2; i >= 0; i --){
            cout << sol[i];
        }
        cout << "\n";
    }

    return 0;
}
