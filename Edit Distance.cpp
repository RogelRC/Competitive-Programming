#include <bits/stdc++.h>
 
using namespace std;
 
int dp[5005][5005];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    string s1, s2;
    char c1, c2;
 
    cin >> s1 >> s2;
 
    int a = s1.size();
    int b = s2.size();
 
    for(int i = 0; i <= a; i ++){
        for(int j = 0; j <= b; j ++){
            if(i == 0){
                dp[i][j] = j;
                continue;
            }
            else if(j == 0){
                dp[i][j] = i;
                continue;
            }
 
            c1 = c2 = '#';
 
            if(i > 0) c1 = s1[i - 1];
            if(j > 0) c2 = s2[j - 1];
 
            if(c1 == c2 && c1 != '#'){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
        }
    }
 
    cout << dp[a][b];
 
    return 0;
}