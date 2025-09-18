#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, a, sum = 0;

    cin >> n;

    for (long long i = 1; i < n; i++)
    {
        cin >> a;
        sum += a;
    }

    cout << (n * (n + 1)) / 2 - sum << "\n";

    return 0;
}