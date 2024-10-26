#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, d;
 
    cin >> n >> d;
 
    vector<pair<int, int> > datos(n);
    vector<int> dp(d + 1);
 
    for(int i = 0; i < n; i ++){
        cin >> datos[i].first;
    }
    for(int i = 0; i < n; i ++){
        cin >> datos[i].second;
    }
 
    for(int i = 0; i < n; i ++){
        for(int j = d; j >= datos[i].first; j --){
            if(j == datos[i].first) dp[j] = max(dp[j], datos[i].second);
            else{
                dp[j] = max(dp[j], dp[j - datos[i].first] + datos[i].second);
            }
        }
    }
 
    cout << dp[d];
 
    return 0;
}