#include <iostream>

// finds the gcd of a and b using the Euclidean Algorithm
int gcd(int a, int b) {
    // base case
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    // testing
    std::cout << gcd(105, 252) << std::endl;
    std::cout << gcd(105, -252) << std::endl;
    std::cout << gcd(2500, 13) << std::endl;
    std::cout << gcd(19, 1425) << std::endl;
}
