#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int casos,cantidad,gasto,sobra,temp;
    cin>>casos;
    while(casos--){
        gasto=0;
        cin>>cantidad;
        while(cantidad>=10){
            sobra=cantidad%10;
            cantidad-=sobra;
            temp=cantidad/10;
            gasto+=cantidad;
            cantidad=temp+sobra;
        }
        sobra=cantidad%10;
        cout<<gasto+sobra<<"\n";
    }
    return 0;
}