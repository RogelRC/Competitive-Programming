#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y;

    while (cin >> x >> y && x != -1 && y != -1){
        if(x == 1 || y == 1){
            cout << 2 * 26 + (max(x, y) + (max(x, y) - 2)) * 38 + max(x, y) * 13;
        }
        else if(x % 2 == 0 || y % 2 == 0){
            cout << 2 * 26 + (13 + 38) * x * y;
        }
        else cout << 2 * 26 + (x * y + 1) * 38 + (x * y) * 13;

        cout << "\n";
    }
    

    return 0;
}