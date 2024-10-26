#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string cadena;
    char cmp = '0';
    int sol = 0, rep;
 
    cin >> cadena;
 
    for(int i = 0; i < cadena.size(); i ++){
 
        if(cadena[i] != cmp){
            cmp = cadena[i];
            rep = 1;
            sol = max(sol, rep);
        }
 
        else{
            rep++;
            sol = max(sol, rep);
        }
    }
 
    cout << sol;
    return 0;
}