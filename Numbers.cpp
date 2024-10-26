#include <bits/stdc++.h>
using namespace std;

int suma(int n, int b) {
    int sum = 0;
    while (n > 0) {
        sum += n % b;
        n /= b;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A;
    cin >> A;

    int total = 0;
    for(int base = 2; base <= A - 1; base ++){
        total += suma(A, base);
    }

    int numerador = total;
    int denominador = A - 2;

    int gcd = __gcd(numerador, denominador);
    numerador /= gcd;
    denominador /= gcd;

    cout << numerador << "/" << denominador;

    return 0;
}