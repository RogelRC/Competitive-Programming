#include <bits/stdc++.h>

using namespace std;

int arr[10];

void unacosa(int n){
    int i = 1;

    while(arr[(i * n) % 10] == -1){
        arr[(i * n) % 10] = i;
        i++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, cantidad, perfecto, num;

    cin >> casos;

    while(casos --){
        for(int i = 0; i < 10; i ++){
            arr[i] = -1;
        }

        cin >> cantidad >> perfecto;

        unacosa(perfecto);

        while(cantidad--){
            cin >> num;

            if((arr[num % 10] != -1 && num >= perfecto * arr[num % 10]) || (num >= perfecto * 10))cout << "YES\n";
            else cout << "NO\n";
        }

    }

    return 0;
}