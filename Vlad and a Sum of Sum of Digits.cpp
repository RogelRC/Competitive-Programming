#include <bits/stdc++.h>

using namespace std;

int memo[2000005];

int DigitsSum(int n){
    int s = 0;

    while(n > 0){
        s += n % 10;
        n /= 10;
    }

    return s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, num;

    for(int i = 1; i <= 200000; i ++){
        memo[i] = DigitsSum(i) + memo[i - 1];
    }

    cin >> casos;

    while(casos --){
        cin >> num;

        cout << memo[num] << "\n";
    }

    return 0;
}