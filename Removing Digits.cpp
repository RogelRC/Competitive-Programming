#include <bits/stdc++.h>
 
using namespace std;
 
int MaxDigit(int n){
    int nmax = 0;
 
    while(n > 0){
        nmax = max(nmax, n % 10);
        n /= 10;
    }
 
    return nmax;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, cont = 0;
 
    cin >> n;
 
    while(n > 0){
        n -= MaxDigit(n);
 
        cont ++;
    }
 
    cout << cont;
 
    return 0;
}