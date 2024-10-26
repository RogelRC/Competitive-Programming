#include <bits/stdc++.h>
 
using namespace std;
 
long long cantidad;
vector<long long> abi, lista;
 
void Update(long long p, long long n){
    while(p <= cantidad){
        abi[p] += n;
 
        p += p & (-p);
    }
}
 
long long Sum(long long p){
    long long suma = 0;
 
    while(p >= 1){
        suma += abi[p];
 
        p -= p & (-p);
    }
 
    return suma;
}
 
int main(){
    long long querys, o, a, b;
 
    cin >> cantidad >> querys;
 
    lista.resize(cantidad + 1);
    abi.resize(cantidad + 1);
 
    for(long long i = 1; i <= cantidad; i ++){
        cin >> lista[i];
 
        Update(i, lista[i]);
    }
 
    while(querys --){
        cin >> o >> a >> b;
 
        if(o == 1){
            Update(a, b - lista[a]);
            lista[a] = b;
        }
 
        else{
            cout << Sum(b) - Sum(a - 1) << "\n";
        }
    }
    return 0;
}