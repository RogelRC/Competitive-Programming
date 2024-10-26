#include<bits/stdc++.h>
using namespace std;
int casos,cantidad,n,pares,impares;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>casos;
    while(casos--){
        pares=impares=0;
        cin>>cantidad;
        while(cantidad--){
            cin>>n;
            if(n%2==0)pares++;
            else impares++;
        }
        if(impares%2==1)cout<<"YES\n";
        else if(pares>=1&&impares>=1)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}