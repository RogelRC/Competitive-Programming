#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, f, l, n;
    char c;

    cin >> casos;

    while(casos --){
        f = INT_MAX;
        l = INT_MIN;

        cin >> n;

        for(int i = 0; i < n; i ++){
            cin >> c;

            if(c == 'B'){
                f = min(f, i);
                l = max(l, i + 1);
            }
        }

        if(f != INT_MAX) cout << l - f << "\n";
        else cout << 0 << "\n";
    }

    return 0;
}
