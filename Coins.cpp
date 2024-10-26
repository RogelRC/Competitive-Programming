#include <bits/stdc++.h>

using namespace std;

vector<int> sol;

void rec(int n){
    if(n == 1){
        sol.push_back(1);
        return;
    }

    for(int i = 2; i * i <= n; i ++){
        if(n % i == 0){
            sol.push_back(n / i);

            rec(n / i);

            return;
        }
    }

    sol.push_back(1);
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;

    cin >> n;

    sol.push_back(n);

    if(n != 1) rec(n);

    for(int i = 0; i < sol.size(); i ++){
        cout << sol[i];
        if(i != sol.size() - 1) cout << " ";
    }

    return 0;
}