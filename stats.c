
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
		}else if(letter!=' '){
            st.consonantCount++;
		}	
 	}
	return st; //is it returning the right count?
}

/**
 * Updates word count in the struct
 * @param st 
 * @param str 
 * @return an updated WordStats struct 
 */
WordStats updateWordCount(WordStats st, const char str[]){
	int length = strlen(str);
	if(length>=1){
		st.wordCount++; //initialize it to be one word
		}
	for(int i=0;str[i];i++){
		if(str[i]==32){
		st.wordCount++;
		}
	}
	return st;
}

/**
 * Outputs vowel and consonant stats
 * @param st WordStats structure
 */
void printVowelConsFreq(WordStats st)
{
	printf("%d\n",st.vowelCount);
	printf("%d\n",st.consonantCount);
	printf("%d\n",st.wordCount);
	float total = st.vowelCount+st.consonantCount;

	float percentVowel = ((st.vowelCount)/(total));
	float percentCons = ((st.consonantCount)/(total));
	printf("Vowels: %d (%.2f), ", st.vowelCount, percentVowel);
	printf("Consonants: %d (%.2f), Total: %.0f ", st.consonantCount, percentCons, total);
	// TODO: print vowel and consonant frequency
}

/**
 * Outputs word count
 * @param st WordStats structure
 */
void printWordCount(WordStats st)
{
	printf("The word count is: %d\n", st.wordCount);
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
