#include <iostream>
#include <cstdlib>
#include <ctime>

void multiply(int* arrayPointer, int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        *(arrayPointer + i) *= (i+1);
    }
}

int main() {
    srand(time(0));

    std::cout << "[ ";
    int array[8];
    for (int i = 0; i < 8; i++) {
        array[i] = rand() % 10 + 10;
        std::cout << array[i] << " ";
    }
    std::cout << "]\n\n";

    int* arrayPointer = &array[0];

    multiply(arrayPointer, 8);

    std::cout << "[ ";
    for (int i = 0; i < 8; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "]\n";
}