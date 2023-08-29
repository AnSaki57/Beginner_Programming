/*
	Calculator for Collatz numbers of a given number
	
	Prompt user to enter a number
	set a while loop
		if number even and loop undone, divide by 2
		if nnumber odd and loop undone, do 3n+1
		print new val
	print no of steps taken
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
	puts("Welcome to 3n+1!");   //Explanation
	puts("The rules are simple, find a natural number that doesn't stop this program!\n");
	puts("The algorithm goes like this:");
	puts("	If the number is odd, we multiply by 3 and add 1  (3n+1)");
	puts("	If the number is even, we divide by 2             (n/2)\n");
	puts("Our claim: Any number you choose ends in 1!");
	printf("Pick a number: ");
	
	int input;                //number that user inputs
	scanf("%d", &input);
	int loop_state = 1;		  //current state of loop(run it/don't run it)
	int loops;
	
	while(input != 1) {
		
		if(input % 2 == 0 & loop_state == 1) {	//even number 
			input = input/2;
			loop_state = 0;
		}
		if(input % 2 == 1 & loop_state == 1) {	//odd number
			input = input * 3 + 1;
		}
		
		loops++;				//counts which loop iteration is going on
		printf("%d\n", input);	//prints current no
		loop_state = 1;			//sets up the if stmts again
	}
	
	printf("\nToo bad, that ended in %d steps!\n", loops);
}
