#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, n, sol, sum, nmax;

    cin >> casos;

    while(casos--){
        cin >> n;
        sol = 0;

        for(int i = 0; i < n; i ++){
            sum = 0;
            nmax = 0;

            sum += (i * (i + 1) * (2 * i + 1)) / 6;

            for(int j = i + 1; j <= n; j ++){
                //cout << j << " " << n - (j - i - 1) << "\n";

                sum += j * (n - (j - i - 1));

                nmax = max(nmax, j * (n - (j - i - 1)));
            }

            sol = max(sol, sum - nmax);
        }

        cout << sol << "\n";
    }

    return 0;
}