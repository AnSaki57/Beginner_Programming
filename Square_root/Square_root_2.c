#include <stdio.h>
#include "sqrt.h"

int main() {
    printf("Enter your number: ");
    int input;
    scanf("%d", &input);

    printf("The square root of %d is %f.\n", input, square_root(input));
}