#include <bits/stdc++.h>

using namespace std;

string cadena;
int t;

//0 - detenido
//1 - cogiendo
//2 - cualquier cosa

int dina(int p, int estado, int a, int b, int c){
    if(p == t) return (a == b && a == c);

    if(estado == 0) return dina(p + 1, 0, a, b, c);
    if(estado == 1) return dina(p + 1, 1, a + (cadena[p] == 'a'), b + (cadena[p] == 'b'), c + (cadena[p] == 'c')) + dina(p + 1, 0, a, b, c);
    if(estado == 2) return dina(p + 1, 1, a + (cadena[p] == 'a'), b + (cadena[p] == 'b'), c + (cadena[p] == 'c')) + dina(p + 1, 2, a, b, c);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> cadena;

    t = cadena.size();

    cout << dina(0, 2, 0, 0, 0) - 1;

    return 0;
}