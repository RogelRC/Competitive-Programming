#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int monedas, cantidad;
    const int mod = pow(10, 9) + 7;
 
    cin >> monedas >> cantidad;
 
    vector<int> mon(monedas);
    vector<int> suma(cantidad + 1);
    suma[0] = 1;
 
    for(int i = 0; i < monedas; i ++){
        cin >> mon[i];
    }
 
    for(int j = 1; j <= cantidad; j ++){
        for(int i = 0; i < monedas; i ++){
            if(j - mon[i] >= 0){
                suma[j] += suma[j- mon[i]];
                suma[j] %= mod;
            }
        }
    }
 
    cout << suma[cantidad];
 
    return 0;
}