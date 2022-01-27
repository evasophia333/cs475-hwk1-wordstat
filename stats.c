
#include "stats.h"
#include <stdio.h>
#include <string.h>

/**
 * Initializes the statistics structure
 * @param st an uninitialized WordStats struct
 * @return an initialized WordStats struct 
 */
WordStats initStats(WordStats st)
{
	st.wordCount = 0;
	st.vowelCount = 0;
	st.consonantCount = 0;
	//st.histo = [];

	// TODO initialize all fields in the st struct before returning it
	return st;
}

/**
 * Updates vowels and consonants in the struct
 * @param st WordStats structure
 * @param input the user-input string
 * @return an updated WordStats struct 
 */
WordStats updateVowelCons(WordStats st, const char str[])
{
	
	for(int i=0;str[i];i++){ 
		char letter = tolower(str[i]); 
        if(letter=='a'|| letter=='e'||letter=='i'||letter=='o'||letter=='u'){
		    st.vowelCount++;
			printf("Num vowels is: %d\n",st.vowelCount);
		}else if(letter!=' '){
            st.consonantCount++;
			printf("Num constonants is: %d\n",st.consonantCount);
		}
 	}
	printVowelConsFreq(st);
	return st; //is it returning the right count?
}

/**
 * Updates word count in the struct
 * @param st 
 * @param str 
 * @return an updated WordStats struct 
 */
WordStats updateWordCount(WordStats st, const char str[])
{
	//loop through the str 
	//if there is a white space then increase the word counter
	//also remeber the letter prior and ensure that it is a letter or number not a white space

	// TODO - update the word count in the st struct before returning it
	return st;
}

/**
 * Outputs vowel and consonant stats
 * @param st WordStats structure
 */
void printVowelConsFreq(WordStats st)
{
	printf("The vowel count is: %d\n", st.vowelCount);
	printf("The constanat count is: %d\n", st.consonantCount);
	// TODO: print vowel and consonant frequency
}

/**
 * Outputs word count
 * @param st WordStats structure
 */
void printWordCount(WordStats st)
{
	printf("The word count is: %d\n", st.wordCount);
	// TODO: prints word count
}

/**
 * Outputs histogram vertically
 * @param st WordStats structure
 */
void printHistogram(WordStats st)
{
	// TODO: Prints vertical histogram
}

/**
 * Update the histogram
 * @param histo	the histogram
 * @param str	the string used to update the histogram
 */
void updateHistogram(int histo[], const char str[])
{
	// TODO: updates the frequencies in the histogram, given the letters in the input string
}
