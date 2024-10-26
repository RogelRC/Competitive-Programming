#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, nmax;
    vector<char> lista;

    while(cin >> a >> b && a && b){
        lista.resize(a);
        b = a - b;

        for(int i = 0; i < a; i ++){
            cin >> lista[i];
        }

        for(int i = 0; i < a && b > 0; i ++){
            nmax = INT_MIN;

            for(int j = i; j < a - b + 1; j ++){
                if(lista[j] - '0' > nmax){
                    nmax = lista[j] - '0';
                    i = j;
                }
            }

            b --;

            cout << nmax;
        }

        cout << "\n";
    }

    return 0;
}