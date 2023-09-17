/*Number guesser, where number is random, 
  and guesses are limited(12-15)*/

#include <stdio.h>
#include <stdlib.h> //for srand function
#include <time.h>	//for time function(to ultimately randomise properly)

int main(){
	printf("Guess my number!You have 11 tries!\n");
	printf("Enter a number(0 to 999): ");
	
	int inp; 		//initialise input
	srand(time(0)); //seed rand() with the time
	int ans = rand() % 1000; //pick a 3-digit no. from rand
	int i;

	//Loop 11 times(no. of attempts available)
	for (; i < 11; i++) {
		scanf("%d", &inp);
		
		if (inp == ans) {
			break; //Exit loop if ans is correct
		} else if (inp > ans) {
			//To make it possible to use logic to arrive
			//at ans, tell if input is less than or greater
			//than actual ans
			
			printf("No, that's greater than the number!\n\nTry again!: ");
			//continue;
		} else if (inp < ans) {
			printf("No, that's smaller than the number!\n\nTry again!: ");
		}
	}

	if (i < 11) {
		printf("Yes, it's %d!\n", ans);
		printf("You did it in %d tries!\n", i);
		return 0;
	} else {
		printf("\nSorry, you lose!\n");
	}
}
