#include <bits/stdc++.h>

using namespace std;

int solve(int x, int y){
    if(x <= 5){
        if(y <= 5) return min(x, y);
        else if(y > 5) return min(x, 10 - y + 1);
    }

    else{
        if(y <= 5) return min(10 - x + 1, y);
        else if(y > 5) return min(10 - x + 1, 10 - y + 1);
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, puntos;
    char c;

    cin >> casos;

    while(casos --){
        puntos = 0;

        for(int i = 1; i <= 10; i ++){
            for(int j = 1; j <= 10; j ++){
                cin >> c;

                if(c == 'X') puntos += solve(i, j);
            }
        }

        cout << puntos << "\n";
    }

    return 0;
}