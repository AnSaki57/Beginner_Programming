/*
    Ask user for input
    Store terms of sequence in an array
    do a for loop 5 times
        (input the algorithm)
        x[i+1] = 0.5 * (x[i] + x[0]/x[i])
    print x[5]
*/

#include <stdio.h>

int main() {
    printf("Enter input: ");
    int input;
    scanf("%d", &input);

    long double x[21];
    x[0] = input;

    for (int i; i < 20; i++) {
        x[i + 1] = 0.5 * (x[i] + x[0] / x[i]);
    }

    printf("The square root of %d is approximately %Lf.\n", input, x[20]);
}