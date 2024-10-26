#include <bits/stdc++.h>
using namespace std;

int dp[61];

int main() {
    int n;
    cin >> n;

    if(n % 2 == 1){
        cout << 0;
        return 0;
    }

    else cout << (int)pow(2, n / 2);

    return 0;
}