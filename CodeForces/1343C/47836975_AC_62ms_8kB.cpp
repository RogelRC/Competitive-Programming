#include <bits/stdc++.h>

using namespace std;

int signo(int n){
    if(n >= 0) return 1;
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, cantidad, ant, n;
    long long sum;

    cin >> casos;

    while(casos --){
        cin >> cantidad;

        cin >> ant;
        sum = 0;

        for(int i = 1; i < cantidad; i ++){
            cin >> n;

            if(signo(n) != signo(ant)){
                sum += ant;

                ant = n;
            }

            else{
                ant = max(ant, n);
            }
        }

        sum += ant;

        cout << sum << "\n";
    }

    return 0;
}