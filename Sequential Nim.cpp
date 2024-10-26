#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, cantidad, n, gana;

    cin >> casos;

    while(casos--){
        cin >> cantidad;

        gana = -1;

        for(int i = 0; i < cantidad; i ++){
            cin >> n;

            if(n > 1 && gana == -1){
                gana = i % 2;
            }
        }

        if(gana == -1)gana = (cantidad - 1) % 2;

        if(gana == 0)cout << "First\n";
        else cout << "Second\n";
    }

    return 0;
}