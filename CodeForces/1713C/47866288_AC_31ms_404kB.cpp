#include <bits/stdc++.h>

using namespace std;

int arr[100005];
void dina(int n){
    if(n < 0) return;

    int cuadrado = sqrt(2 * n);
    cuadrado *= cuadrado;

    int a = cuadrado - n;

    dina(a - 1);

    while(a <= n){
        arr[a] = n;
        arr[n] = a;

        a ++;
        n --;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, n;

    cin >> casos;

    while(casos--){
        cin >> n;

        dina(n - 1);

        for(int i = 0; i < n; i ++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}