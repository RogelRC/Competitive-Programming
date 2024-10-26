#include <iostream>
 
using namespace std;
 
long long Sol(long long a, long long b){
    long long x, dif;
    long long  diag;
 
    x = max(a, b);
 
    diag = x * (x - 1) + 1;
 
    if(a == b)return diag;
 
    dif = max(x - a, x - b);
 
    if(a > b){
        if(x % 2 == 0)return diag + dif;
        else return diag - dif;
    }
 
    else{
        if(x % 2 == 0)return diag - dif;
        else return diag + dif;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    long long casos, a, b;
    cin >> casos;
 
    while(casos --){
        cin >> a >> b;
        cout << Sol(a, b) << "\n";
    }
 
    return 0;
}