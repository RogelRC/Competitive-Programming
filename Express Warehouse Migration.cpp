#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, sol = 0;

    cin >> a >> b;

    while (a > 0){
        a -= b;
        sol ++;
    }
    
    cout << sol;

    return 0;
}