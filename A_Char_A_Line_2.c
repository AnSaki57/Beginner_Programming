/*Takes a string input from user
  and outputs that string, 
  one char a line*/

#include <stdio.h>
#include <string.h>

int main() {
	
	printf("Enter a string: ");     //Prompt
	char string[150];
	
	for(int i = 0; i < 150; i++) {	//Make evry char in string into '~'
		string[i] = '~';
	}
	
	scanf("%s", &string[0]);		//User enters n changes '~'s into chars
	
	for(int i=0; i < 150; i++ ) {    //start fof a for loop
		if(string[i] != '~') {		//Execute only if char isn't '~'
			printf("%c\n", string[i]);
		}
	}
}
