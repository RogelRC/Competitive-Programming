#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, n, p;
    vector<int> lista(30);

    cin >> casos;

    while(casos --){
        fill(lista.begin(), lista.end(), 0);

        cin >> n;

        while(n --){
            cin >> p;

            for(int i = 0; i < 30; i ++){
                if(lista[i] == p){
                    cout << char(i + 97);

                    lista[i] ++;
                    break;
                }
            }
        }
        cout << "\n";
    }

    return 0;
}
