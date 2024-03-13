#include <bits/stdc++.h>

using namespace std;

int sum(int n){
    int s = 0;
    while(n > 0){
        s += n % 10;
        n /= 10;
    }
    return s;
}

int findNext(int n){
    n ++;

    while(sum(n) != 10){
        n ++;
    }

    return n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int sol = 0;

    int n;

    cin >> n;

    while(n --){
        sol = findNext(sol);
    }

    cout << sol;

    return 0;
}