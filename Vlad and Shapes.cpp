#include <bits/stdc++.h>

using namespace std;

int tabla[15];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, n;
    char a;
    bool b;

    cin >> casos;

    while(casos --){
        cin >> n;

        b = true;
        memset(tabla, 0, sizeof(tabla));

        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                cin >> a;

                if(a == '1') tabla[i] ++;
            }
        }

        for(int i = 0; i < n; i ++){
            if(tabla[i] == 0) continue;

            if(tabla[i] != tabla[i + 1]){
                b = false;
                break;
            }

            if(tabla[i] == tabla[i + 1]){
                break;
            }
        }

        if(b == true) cout << "SQUARE\n";
        else cout << "TRIANGLE\n";
    }


    return 0;
}