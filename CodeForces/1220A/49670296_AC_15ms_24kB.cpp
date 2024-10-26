#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int o = 0, n = 0, e = 0, z = 0, r = 0, T, ri;
    char c;

    cin >> T;

    while(T --){
        cin >> c;

        if(c == 'o') o ++;
        else if(c == 'n') n ++;
        else if(c == 'e') e ++;
        else if(c == 'z') z ++;
        else if(c == 'r') r ++;
    }

    ri = min(o, min(n, e));

    for(int i = 0; i < ri; i ++){
        cout << 1 << " ";
    }

    for(int i = 0; i < z; i ++){
        cout << 0 << " ";
    }

    return 0;
}