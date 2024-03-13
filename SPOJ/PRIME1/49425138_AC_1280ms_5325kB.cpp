#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    if(n == 0 || n == 1) return false;

    for(int i = 2; i * i <= n; i ++){
        if(n % i == 0) return false;
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, a, b;

    cin >> casos;

    while(casos --){
        cin >> a >> b;

        for(int i = a; i <= b; i ++){
            if(isPrime(i) == true) cout << i << "\n";
        }

        cout << "\n";
    }

    return 0;
}