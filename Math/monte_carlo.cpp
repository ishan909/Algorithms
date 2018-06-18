// Monte Carlo pi estimation

#include <iostream>

int main() {
    unsigned inside = 0; // count of how many random elems fall within a circle
    unsigned trials = 50000000;
    for (unsigned count = 1; count < trials; count++) {
        // random x and y values between -1 and 1
        double rand_x = (rand() % 200000000) / 100000000.0 - 1;
        double rand_y = (rand() % 200000000) / 100000000.0 - 1;
        if (rand_x * rand_x + rand_y * rand_y < 1) {
            // if the random value falls in a radius 1 circle, increase count
            inside++;
        }
    }
    // estimate pi
    std::cout << "PI: " << 4.0 * inside / (double) trials << std::endl;

    return 0;
}
