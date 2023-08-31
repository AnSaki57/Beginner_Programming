/*
	First, let user input range of numbers
	For each number in loop
		for each number less than selected number (excluding 1 and itself)
			check for divisibility
			if divisible, not prime
		print if prime
*/

#include <stdio.h>

int main() {
	puts("Welcome to Prime counter! Get all the prime numbers within a certain range!");
	int lwr = 0;  						  //Lower bound of input range
	int highr = 0;						  //Upper bound of input range
	
	printf("Enter lower limit: ");
	scanf("%d", &lwr);
	printf("Enter higher limit: ");
	scanf("%d", &highr);
	
	int Primes[1500];					  //Array storing (max 1500) primes incase we
	int counter = 0;					  //need to call them again
	
	//check each number for primeness
	for (int i = lwr; i <= highr; i++) {  //Picks a number in range to check its primeness
		int is_prime = 0;				  //Assume it's prime
		
		//check each number less than selected number
		for (int j = 2; j < i; j++) {	  //Check every number less than it for factors
			if (i % j == 0) {
				is_prime++;				  //If factor found, increase
			}							  //is_prime's val so no longer prime
		}
		
		//case where 1 is in range, so that 1 isn't printed as prime
		if (i == 1) {
			is_prime++;
		}
		
		//print primes
		if (is_prime == 0) {		      //is_prime is 0 only for primes, i.e, no factors
			Primes[counter] = i;
			counter++;
			
			printf("%d\n", i);
		}
	}
	
	
}
