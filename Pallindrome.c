/*
	1)First, calc number of digits in a number
	2)Second, find how to calc the val of a digit in a number
	3)Third, put an if loop inside a for loop to ocmpare each pair of digits
*/

#include <stdio.h>
#include <math.h>

int main() {
	
	//1)Count number of digits
	/*
		Take input
		Run a for loop and find remainder of input w increasing pwrs of 10, until 
		remainder = input
			increase digit counter for every iteration
	*/
	
	puts("Check if a given natural number is a pallindrome or not!");
	printf("Enter your number: ");
	int input = 0;
	scanf("%d", &input);				 //Take input
	
	int digit_count = 0;				 //counter for digits
	int loopend = 0;					 //End loop when this var != 0
	
	for (int i = 0; loopend == 0; i++) { //keep modding input by pwrs of 10 until == input
		if (input % (int) pow(10,i) != input) { //if it's not 0, increase
			digit_count++;				 
		}
		else {							 //else, end loop
			loopend++;
		}
	}
	
	//If we need to know what vals r stored in "input", & "digit_count"
	//printf("The input, %d, has %d digits.\n", input, digit_count);
	
	
	//2)Create an array of the digits in the input
	/*
		Take a certain digit
			1)% that number with the pwr of 10 such that 
			req digit is leading digit in rem
			2)div that rem by the pwr of 10 just smaller than the prev pwr
	*/
	
	int digit[25];
	for (int i = 1; i <= digit_count; i++) { //eg. input is 2345 and we need to store 4
		digit[i] = input % (int) pow(10,i);  //digit = 2345 % 100 (viz. 45)
		digit[i] /= (int) pow(10,i-1);		 //digit = digit / 10 (viz. 4)
	}
	
	//If we ever need to see what digits the array is storing, in what manner
	/*
		for (int i = 1; i <= digit_count; i++) {
			printf("%d\n", digit[i]);
		}
	*/
	
	
	//3)Compare the units in the array to see if they match
	loopend = 0; //recycle loopend, it will remain 0 for a pallindrome
	for (int i = 1; i <= digit_count / 2 + 1; i++) {  //check every pair of digits in
		if (digit[i] != digit[digit_count + 1 - i]) { //array to check for equality 
			loopend++;								  
		}
	}
	
	printf("%d is ", input);
	if (loopend != 0) {  //if not a pallindrome, print the extra word 'not'
		printf("not ");
	}
	printf("a pallindrome.\n");
}
