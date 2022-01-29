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
    int notNum = 1;
	char oldArr[MAX_INPUT_LEN];
	int counter =0;
	WordStats ws;
	ws = initStats(ws);
	printf("Enter strings (# to stop):\n");
	while (notNum!=0){ 
		fgets(input, MAX_INPUT_LEN, stdin);
		if (input[0] == '#' ){ //user enters #
			notNum = 0;
		}else{ // otherwise update 
			ws = updateVowelCons(ws, input);
			ws = updateWordCount(ws, input);
			updateHistogram(ws.histo, input);
			for(int i=0;input[i];i++){ //this is the array for printing the histogram
				oldArr[counter] = input[i];
				counter++;
			}
		}
	}
	while(quit!=0){
	int userChoice = getMenuOption();
	if(userChoice==1){
		printVowelConsFreq(ws);
		printf("\n");
	}else if(userChoice==2){
		printWordCount(ws);
		printf("\n");
	}else if(userChoice==3){
		printHistogram(ws, oldArr);
		printf("\n");
	}else if(userChoice==4){
		quit=0;
		main(argc, argv);
	}else if(userChoice==5){
		quit = 0;
		printf("Exiting...\n");
	}
	}
	return 0;
}
