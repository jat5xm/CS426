#include <iostream>

using namespace std;

/// function to compute the GCD and the coefficients of Bézout's identity (x, y)
int extendedEuclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1; // to store results of recursive call
    int gcd = extendedEuclid(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

// function to compute the multiplicative inverse of 'a' modulo 'm'
int multiplicativeInverse(int a, int m) {
    int x, y;
    int gcd = extendedEuclid(a, m, x, y);
    if (gcd != 1) {
        cout << "Multiplicative inverse doesn't exist." << endl;
        return -1;
    } else {
        // make sure x is positive
        return (x % m + m) % m;
    }
}

int main() {
    int x, y;

    // Part (a) GCD(10012012, 2314213)
    int a1 = 10012012, b1 = 2314213;
    int gcd1 = extendedEuclid(a1, b1, x, y);
    cout << "GCD(" << a1 << ", " << b1 << ") = " << gcd1 << endl;

    // Part (b) GCD(28176412, 29108188)
    int a2 = 28176412, b2 = 29108188;
    int gcd2 = extendedEuclid(a2, b2, x, y);
    cout << "GCD(" << a2 << ", " << b2 << ") = " << gcd2 << endl;

    // Part (c) GCD(38172, 23812188)
    int a3 = 38172, b3 = 23812188;
    int gcd3 = extendedEuclid(a3, b3, x, y);
    cout << "GCD(" << a3 << ", " << b3 << ") = " << gcd3 << endl;

    // Part (d) Multiplicative inverse of 12091 mod 24123123
    int a4 = 12091, m1 = 24123123;
    int inv1 = multiplicativeInverse(a4, m1);
    if (inv1 != -1)
        cout << "Multiplicative inverse of " << a4 << " mod " << m1 << " = " << inv1 << endl;

    // Part (e) Multiplicative inverse of 28173928 mod 129182771
    int a5 = 28173928, m2 = 129182771;
    int inv2 = multiplicativeInverse(a5, m2);
    if (inv2 != -1)
        cout << "Multiplicative inverse of " << a5 << " mod " << m2 << " = " << inv2 << endl;

    return 0;
}
