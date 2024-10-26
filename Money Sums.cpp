#include <bits/stdc++.h>
 
using namespace std;
 
int n, s;
vector<int> lista;
vector<int> sumas;
int dp[105][100005];
 
void solve(int p, int sum){
    if(p == n){
        dp[p][sum] = true;
        return;
    }
    if(dp[p][sum] == true) return;
 
    solve(p + 1, sum + lista[p]);
    solve(p + 1, sum);
 
    dp[p][sum] = true;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n;
 
    lista.resize(n);
 
    for(int i = 0; i < n; i ++){
        cin >> lista[i];
 
        s += lista[i];
    }
 
    solve(0, 0);
 
    for(int i = 0; i <= n; i ++){
        for(int j = 1; j <= s; j ++){
            if(dp[i][j] == true){
                sumas.push_back(j);
            }
        }
    }
 
    sort(sumas.begin(), sumas.end());
    unique(sumas.begin(), sumas.end());
 
    s = 0;
 
    for(int i = 0; i < sumas.size(); i ++){
        s ++;
 
        if(i < sumas.size() - 1 && sumas[i] > sumas[i + 1]) break;
    }
 
    cout << s << "\n";
 
    for(int i = 0; i < sumas.size(); i ++){
        cout << sumas[i] << " ";
        
        if(i < sumas.size() - 1 && sumas[i] > sumas[i + 1]) break;
    }
 
    return 0;
}