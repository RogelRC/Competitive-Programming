#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    long long cantidad, querys, a, b;
 
    cin >> cantidad >> querys;
 
    vector<long long> lista(cantidad + 1);
 
    for(long long i = 1; i <= cantidad; i ++){
        cin >> lista[i];
        lista[i] += lista[i - 1];
    }
 
    while(querys --){
        cin >> a >> b;
 
        cout << lista[b] - lista[a - 1] << "\n";
    }
    return 0;
}