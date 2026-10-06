#include <iostream>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int reduce(int &num, int &denom) {

    if (num <= 0 || denom <= 0) {
        return 0;
    }

    int gcdiv = gcd(num, denom);

    num = num / gcdiv;
    denom = denom / gcdiv;

    return 1;
}

int main() {

    int m = 63;
    int n = 210;
    if (reduce(m,n))
        std::cout << m << '/' << n << std::endl;
    else
        std::cout << "fraction error" << std::endl;


    return 0;
}