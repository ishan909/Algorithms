// Generates a vector of prime numbers using the Sieve of Eratosthenes algorithm
#include <vector>
#include <iostream>
#include <cmath>

/**
 * Produces a list of primes numbers from [2, M]
 * @param M the value that we want to find primes under
 * @return vector of primes <= M
 */
std::vector<int> generate_primes(int M) {
    std::vector<int> primes;
    if (M < 2) {
        return primes;
    }

    // fill the vector with values
    for (int i = 2; i <= M; i++) {
        primes.push_back(i);
    }

    // Use Sieve of Eratosthenes to remove non-prime values
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i + 1; j < primes.size(); j++) {
            if (primes[j] % primes[i] == 0) {
                // removes a value from the vector if it is divible by a smaller number
                primes.erase(primes.begin() + j);
            }
        }
    }
    return primes;
}

int main() {
    // will generate a list of primes <= max
    int max = 200;
    std::vector<int> primes = generate_primes(max);

    std::cout << "Primes less than " << max << ": ";
    for (int i = 0; i < primes.size(); i++) {
        std::cout << primes[i] << " ";
    }
    std::cout << std::endl;
}
