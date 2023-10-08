#include <iostream>

int Recursive(int iterations);

int main() {
    std::cout << "Enter number of iterations: ";
    int numberOfIterations;
    std::cin >> numberOfIterations;

    for (int i = 0; i < numberOfIterations; i++) {
        std::cout << Recursive(i + 1);
        std::cout << std::endl;
    }
}

int Recursive(int iterations) {
    if (iterations <= 0) {
        return -999;
    }
    if (iterations == 1) {
        return 1;
    } else if (iterations % 2 == 0) {
        return 1 + Recursive(iterations / 2);
    } else {
        return 1 - Recursive(iterations - 1);
    }
}