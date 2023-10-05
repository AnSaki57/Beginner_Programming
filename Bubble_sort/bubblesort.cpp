/*
    Take length or array
    Take elems of array
    for
        if arri > arri+1
            rev em
            changemade = true
*/

#include <iostream>

//takes array and (useful)size of array, and bubble-sorts it (descending order)
void bubblesort(int array[], int size) {
    
    //loop until you pass through the for loop without making a single swap
    bool Changes = true;
    while (Changes) {
        Changes = false;

        for (int i = 0; i < size - 1; i++) {
            
            //if you encounter a swap
            if (array[i] < array[i+1]) {
                int swap = array[i];
                array[i] = array[i+1];
                array[i+1] = swap;
                Changes = true;
            }
        }
    }
}

int main() {
    //prompt user for array size
    int size = 0;
    do {
        std::cout << "Enter number of numbers: ";
        std::cin >> size;
    } while (size <= 0 || size > 50);

    int array[50];
    
    //ask user input
    for (int i = 0; i < size; i++) {
        std::cout << "Enter number " << i + 1 << ": ";
        std::cin >> array[i];
    }

    //bubblesort the array
    bubblesort(array, size);

    //print descending order
    std::cout << "\nDescending:\n";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    //print ascending order
    std::cout << "\nAscending:\n";
    for (int i = 0; i < size; i++) {
        std::cout << array[size - i - 1] << ' ';
    }
    std::cout << std::endl;
}