#include <bits/stdc++.h>

using namespace std;

long long mayor(long long n){
    long long temp = -1;

    while(n > 0){
        temp = max(temp, n % 10);
        n /= 10;
    }

    return temp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long num, sol = 0;

    cin >> num;

    while(num > 0){
        sol ++;

        num -= mayor(num);
    }

    cout << sol;
}