#include <iostream>

// finds the gcd of a and b using the Euclidean Algorithm
int gcd(int a, int b) {
    while (b > 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}


int main() {
    std::cout << gcd(105, 252) << std::endl;
}
