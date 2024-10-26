#include <bits/stdc++.h>

using namespace std;

char arr[55];
int n;

int sol(int p, int s){
    if(p >= n || s == 3) return 0;

    if(arr[p] == '*'){
        if(s >= 1) return 0;
        return sol(p + 1, s + 1);
    }

    else if(arr[p] == '@') return 1 + sol(p + 1, 0);

    else if(arr[p] == '.') return sol(p + 1, 0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos;

    cin >> casos;

    while(casos --){
        cin >> n;

        for(int i = 0; i < n; i ++){
            cin >> arr[i];
        }

        cout << sol(0, 0) << "\n";
    }

    return 0;
}
