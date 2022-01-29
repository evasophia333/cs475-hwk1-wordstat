#include <stdio.h>

/**
 * Prints out the Word Stats menu options and scans the user input.
 * @return int the option the user selected
 */
int getMenuOption()
{
	int userInput;
	printf("*** WORD STATS MENU ***\n");
	printf("Enter 1 to print vowel and consonant frequency.\n");
	printf("Enter 2 to print word count.\n");
	printf("Enter 3 to print histogram.\n");
	printf("Enter 4 to return to inputting more strings.\n");
	printf("Enter 5 to quit.\n");
	scanf("%d",&userInput);
	if(userInput>5||userInput<1){ //Catches the error if the user inputs a different number
		printf("ERROR, try a number between one and five!\n");
		printf(getMenuOption()); //recursive call because they did not choose the right number
	}else {
	return userInput;
	}
}