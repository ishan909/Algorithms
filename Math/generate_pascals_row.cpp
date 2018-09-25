#include <iostream>
#include <string>
#include <unordered_map>

unsigned long factorial(unsigned long val, std::unordered_map<unsigned long, unsigned long> *& map) {
    if (val == 0 | val == 1) {
        return 1;
    }
    std::unordered_map<unsigned long, unsigned long>::const_iterator got = map->find(val);
    if (got == map->end()) {
        unsigned long fact = factorial(val - 1, map) * val;
        std::pair<unsigned long, unsigned long> pair(val, fact);
        map->insert(pair);
        return fact;
    } else {
        return got->second;
    }
}

void dp_triangle_row() {
    std::unordered_map<unsigned long, unsigned long> * factorials = new std::unordered_map<unsigned long, unsigned long>();
    unsigned long fact_k, fact_n_k, fact_n, current;

    for (unsigned long n = 0; n < 21; n++) {
        for (unsigned long k = 0; k <= n; k++) {
            fact_k = factorial(k, factorials);
            fact_n_k = factorial(n - k, factorials);
            fact_n = factorial(n, factorials);
            current = fact_n / fact_k / fact_n_k;
            std::cout << current << " ";
        }
        std::cout << std::endl;
    }
    delete factorials;
}

void multiplicative_way() {
    for (unsigned long n = 0; n < 21; n++) {
        for (unsigned long k = 0; k <= n; k++) {
            unsigned long total = 1;
            for (unsigned long i = 1; i <= k; i++) {
                total = total * (n + 1 - i) / i;
            }
            std::cout << total << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    dp_triangle_row();
    multiplicative_way();
}
