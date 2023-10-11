/*
    Create a C program that includes a menu with the following options:
    
    Enter two strings
    Concatenate two strings
    Find the length of a string
    Compare two strings
    Copy one string to another
    Reverse a string
    Exit
    
    Implement a loop in main to repeatedly display the menu and perform the selected operations 
    until the user chooses to exit.
    
    Strings can have a maximum length of 100 characters. Ensure that your program handles 
    boundary cases and does not exceed the allocated memory for character arrays.
    
    Do not use <string.h>

    Implement functions for each menu option:
    
    void enterStrings(char str1[], char str2[]): This function should prompt the user to enter two 
    strings and store them in character arrays str1 and str2.
    
    void concatenateStrings(char str1[], char str2[]): This function should concatenate str2 to the end of str1.
    int findStringLength(char str[]): This function should calculate and return the length of the input string str.
    int compareStrings(char str1[], char str2[]): This function should compare str1 and str2 and return:
    0 if the strings are equal.
    A positive number if str1 is greater.
    A negative number if str2 is greater.
    void copyString(char dest[], char src[]): This function should copy the contents of src to dest.
    void reverseString(char str[]): This function should reverse the characters in str.

    
*/

#include <stdio.h>

//define the various functions
void enterStrings(char str1[], char str2[]);        
void concatenateStrings(char str1[], char str2[]);  
int findStringLength(char str[]);                   
int compareStrings(char str1[], char str2[]);       
void copyString(char dest[], char src[]);           
void reverseString(char str[]);   

void printMenu();

int main() {
    puts("Welcome to string manipulator!");

    char str1[100];
    char str2[100];

    //initialise str1 and str2's elems to spaces
    for (int i = 0; i < 100; i++) {
        str1[i] = ' ';
        str2[i] = ' ';
    }

    //ask user for strings
    enterStrings(str1, str2);

    while (1) {
        char input = '\n';
        while ((input = getchar()) != '\n' && input != EOF); //Gets rid of the buffer characters
        
        printMenu(); //print the menu
        scanf("%c", &input);
        

        //take user input on what to do
        if (input == '1') {           //print the 2 strings
            printf("String 1: %s\n", str1);
            printf("String 2: %s\n", str2);
        } else if (input == '2') {    //concatenate the 2 strings into str1
            concatenateStrings(str1, str2);
            printf("%s\n", str1);
        } else if (input == '3') {    //find length of either string
            printf("If you want to find length of %s, print 1. Else, for %s, print 2: \n", str1, str2);
            puts("Enter choice: ");
            int choice;
            scanf("%d", &choice);

            if (choice == 1) {      //find length of str1
                int c;
                while ((c = getchar()) != '\n' && c != EOF); //Gets rid of the buffer characters
                
                printf("%d\n", findStringLength(str1));
            } else if (choice == 2) {//find length of str2
                printf("%d\n", findStringLength(str2));
            } else {                //incorrect input
                printf("Incorrect choice.\n");
                continue;
            }
        } else if (input == '4') {   //compare the 2 strings
            if (compareStrings(str1, str2) == 1) {
                printf("%s is bigger than %s.\n", str1, str2);
            } else if (compareStrings(str1, str2) == 2) {
                printf("%s is bigger than %s.\n", str2, str1);
            } else {
                puts("They're the same strings.");
            }
        } else if (input == '5') {    //copies str1 into 2, or str2 into 1
            printf("To copy %s \nto \n%s, type 1. Else, type 2 to do the opposite.", str1, str2);
            int choice;
            scanf("%d", &choice);

            if (choice == 1) {      //put str1 into str2
                int c;
                while ((c = getchar()) != '\n' && c != EOF); //Gets rid of the buffer characters
                
                copyString(str2, str1);
                printf("String 1: %s\n", str1);
                printf("String 2: %s\n", str2);
            } else if (choice == 2) {//put str2 into str1
                int c;
                while ((c = getchar()) != '\n' && c != EOF); //Gets rid of the buffer characters

                copyString(str1, str2);
                printf("String 1: %s\n", str1);
                printf("String 2: %s\n", str2);
            } else {
                printf("Incorrect choice.\n");
                continue;
            }
        } else if (input == '6') {    //reverses chars | srahc sesrever 
            char inputString[100];
            int choice;
            printf("\nIf %s is your input, type 1. If %s is, type 2.\nEnter input: ", str1, str2);
            scanf("%d", &choice);

            if (choice == 1) {
                for (int i = 0; i < 100; i++)
                    inputString[i] = str1[i];
            } else {
                for (int i = 0; i < 100; i++)
                    inputString[i] = str2[i];
            }

            reverseString(inputString);
            if (choice == 1) {
                for (int i = 0; i < 100; i++)
                    str1[i] = inputString[i];
            } else {
                for (int i = 0; i < 100; i++)
                    str2[i] = inputString[i];
            }
            printf("%s\n", inputString);
        } else if (input == '7') {
            break;
        }

        while ((input = getchar()) != '\n' && input != EOF); //Gets rid of the buffer characters
    }
}

void enterStrings(char str1[], char str2[]) {
    puts("Enter 2 strings:");
    printf("String 1: ");
    scanf("%99[^\n]", str1); // takes input until scanf encounters a '\n'

    int c;
    while ((c = getchar()) != '\n' && c != EOF); //Gets rid of the buffer characters

    printf("String 2: ");
    scanf("%99[^\n]", str2);
}

void concatenateStrings(char str1[], char str2[]) {
    int breakit = findStringLength(str1);

    for (int i = 0; i + breakit < 100; i++) {
        str1[i + breakit] = str2[i];
    }
}

int findStringLength(char str[]) {
    for (int i = 0; i < 99; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ') {   //until 2 ' ' are simulaneously encountered(which more often than not guarantees end of string), consider as part of length
            return i - 1;
        }
    }
}

int compareStrings(char str1[], char str2[]) {
    for (int i = 0; i < 100; i++) {
        if (str1[i] > str2[i]) {
            return 1;
        } else if (str1[i] < str2[i]) {
            return 2;
        } else if (findStringLength(str1) > findStringLength(str2)) {
            return 1;
        } else if (findStringLength(str1) < findStringLength(str2)) {
            return 2;
        } else if (str1[99] == str2[99]) {
            return 3;
        }
    }
}

void copyString(char dest[], char src[]) {
    for (int i = 0; i < 100; i++) {
        dest[i] = src[i];
    }
}

void reverseString(char str[]) {
    char rev[100];
    for (int i = 0; i < 100; i++) {
        rev[i] = ' ';
    }
    int lengthString = findStringLength(str);

    for (int i = 0; i < lengthString; i++) {
        rev[i] = str[lengthString - 1 - i];
    }
    for (int i = 0; i < lengthString; i++) {
        str[i] = rev[i];
    }
}

void printMenu() {
    puts("\nChoose your operations:");
        puts("\t1 - Print the strings");
        puts("\t2 - Concatenate two strings");
        puts("\t3 - Find the length of a string");
        puts("\t4 - Compare two strings");
        puts("\t5 - Copy one string to another");
        puts("\t6 - Reverse a string");
        puts("\t7 - Exit");

        printf("\nEnter choice: ");
}