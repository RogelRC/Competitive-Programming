#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n;
    const int mod = pow(10, 9) + 7;
 
    cin >> n;
 
    vector<int> lista(n + 1);
 
    lista[0] = 1;
 
    for(int i = 1; i <= n; i ++){
        lista[i] += lista[i - 1]; lista[i] %= mod;
        if(i >= 2)lista[i] += lista[i - 2]; lista[i] %= mod;
        if(i >= 3)lista[i] += lista[i - 3]; lista[i] %= mod;
        if(i >= 4)lista[i] += lista[i - 4]; lista[i] %= mod;
        if(i >= 5)lista[i] += lista[i - 5]; lista[i] %= mod;
        if(i >= 6)lista[i] += lista[i - 6]; lista[i] %= mod;
    }
 
    cout << lista[n];
 
    return 0;
}