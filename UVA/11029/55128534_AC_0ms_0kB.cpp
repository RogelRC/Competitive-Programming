#include <bits/stdc++.h>

using namespace std;

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    
    while (T--) {
        long long n, k;
        cin >> n >> k;
        
        long long lastThree = modExp(n, k, 1000);
        
        double logVal = k * log10(n);
        double fractionalPart = logVal - floor(logVal);
        long long firstThree = (long long)(pow(10, fractionalPart) * 100);
        
        cout << firstThree << "..." << setw(3) << setfill('0') << lastThree << endl;
    }

    return 0;
}
