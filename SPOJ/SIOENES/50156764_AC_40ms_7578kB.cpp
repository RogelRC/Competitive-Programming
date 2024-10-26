#include <bits/stdc++.h>

using namespace std;

int arr[1000005];

void criba(){
    for(int i = 2; i <= 1000000; i ++){
        if(arr[i] == 1) continue;

        for(int j = i + i; j <= 1000000; j += i){
            arr[j] = 1;
        }
    }

    for(int i = 2; i <= 1000000; i ++){
        if(arr[i] == 0) arr[i] = 1;
        else arr[i] = 0;

        arr[i] += arr[i - 1];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    criba();

    int casos, n;

    cin >> casos;

    while(casos --){
        cin >> n;

        cout << arr[n] << "\n";
    }

    return 0;
}