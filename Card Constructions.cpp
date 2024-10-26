#include <bits/stdc++.h>

using namespace std;

int n;

int sol(int altura){
    n -= 2 + 3 * altura;

    if(n < 0)return n + (2 + 3 * altura);

    return sol(altura + 1);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, ant, solu;

    cin >> casos;

    while(casos --){
        solu = 0;

        cin >> n;

        while(n >= 2){
            solu ++;

            n = sol(0);
        }

        cout << solu << "\n";
    }

    return 0;
}