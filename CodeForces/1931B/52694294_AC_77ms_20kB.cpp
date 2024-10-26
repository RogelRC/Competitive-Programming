#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, n, sum;
    vector<int> lista;
    vector<int> ta;
    bool flag;

    cin >> casos;

    while(casos --){
        sum = 0;
        flag = true;

        cin >> n;

        lista.resize(n + 1);
        ta.resize(n + 1);

        for(int i = 1; i <= n; i ++){
            cin >> lista[i];

            sum += lista[i];
        }

        sum = sum / n;

        for(int i = 1; i <= n; i ++){
            ta[i] = lista[i] - sum;
            ta[i] += ta[i - 1];

            if(ta[i] < 0){
                flag = false;
                break;
            }
        }

        if(flag == false){
            cout << "NO\n";
        }
        else cout << "YES\n";
    }

    return 0;
}
