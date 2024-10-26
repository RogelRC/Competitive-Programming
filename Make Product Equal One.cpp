#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, a, sol = 0, negativos = 0, ceros = 0;
    
    cin >> n;

    for(long long i = 0; i < n; i ++){
        cin >> a;

        if(a == 0) ceros ++;
        else if(a < 0){
            sol += abs(a) - 1;
            negativos ++;
        }
        else{
            sol += a - 1;
        }
    }

    for(long long i = 0; i < ceros && i < negativos;){
        if(negativos % 2 == 1) negativos --;
        ceros --;
        sol ++;
    }

    sol += 2 * (negativos % 2);
    sol += ceros;

    cout << sol;

    return 0;
}