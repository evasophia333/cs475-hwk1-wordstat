#include <stdio.h>
#include <string.h>
#include "stats.h"
#include "menu.h"

#define MAX_INPUT_LEN 128 /** maximum length of input users can enter */

/**
 * Main function
 * 
 * @param argc the number of command line arguments (ignore for this assignment)
 * @param argv an array of command line arguments (ignore for this assignment)
 */
int main(int argc, char **argv)
{
	char input[MAX_INPUT_LEN]; //holds user-input string
	int quit = 1;
	// TODO: repeatedly print menu options and prompt for an option
	// TODO: display the proper output
	WordStats ws;
	initStats(ws);
	while(quit!=0){
	int userChoice = getMenuOption();
	if(userChoice==1){
		printVowelConsFreq(ws);
		printf("\n");
	}else if(userChoice==2){
		printWordCount(ws);
		printf("\n");
	}else if(userChoice==3){
		printHistogram(ws);
		printf("\n");
	}else if(userChoice==4){
		//have the user input strings 
	}else if(userChoice=5){
		quit =0;
	}

	}
	

	printf("Exiting...\n");
	return 0;
}
