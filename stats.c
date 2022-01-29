
#include "stats.h"
#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26


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
	for(int a=0;a<=ALPHABET_SIZE;a++){ //initialize histo
		st.histo[a]=0;
	}
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
		int letterNum = (int)letter;
		if(letterNum>=97 && letterNum<=123){ //ensures it is a letter
        if(letter=='a'|| letter=='e'||letter=='i'||letter=='o'||letter=='u'){
		    st.vowelCount++;
		}else if(letter!=' '){
            st.consonantCount++;
		}	
		}
 	}
	return st; 
}

/**
 * Updates word count in the struct
 * @param st 
 * @param str 
 * @return an updated WordStats struct 
 */
WordStats updateWordCount(WordStats st, const char str[]){
	int length = strlen(str);
	int letterNum = 0;
	if(length>=1){
		letterNum = (int)str[1];
		if(letterNum>=97 && letterNum<=123){ //ensures it is a number
		st.wordCount++; //initialize it to be one word
		}
	}
	for(int i=0;str[i];i++){
		int letterNum = (int)str[i];
		if(str[i]==32){
		st.wordCount++;
		}
		letterNum =0;
	}
	return st;
}

/**
 * Outputs vowel and consonant stats
 * @param st WordStats structure
 */
void printVowelConsFreq(WordStats st)
{
	float total = st.vowelCount+st.consonantCount;
	float percentVowel = ((st.vowelCount)/(total))*100;
	float percentCons = ((st.consonantCount)/(total))*100;
	printf("Vowels: %d (%.2f%), ", st.vowelCount, percentVowel);
	printf("Consonants: %d (%.2f%), Total: %.0f ", st.consonantCount, percentCons, total);
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
void printHistogram(WordStats st, const char str[])
{
	int copyhist[ALPHABET_SIZE];
	for(int a=0;a<ALPHABET_SIZE;a++){ //initialize copyhist
		copyhist[a]=0;
	}
	int counter =0;
	for(int i=0;str[i];i++){
		if(isalpha(str[i])){
		if(islower(str[i])){	
		st.histo[(str[i]-97)]++; //increases the count for elements that are repeated
		copyhist[(str[i]-97)]++; //increases the count for another array that we will modify
		if(copyhist[(str[i]-97)]>counter){
			counter = copyhist[(str[i]-97)];
		}
		}else if(isupper(str[i])){
			st.histo[(str[i]-65)]++; //increases the count for elements that are repeated
			copyhist[(str[i]-65)]++; //increases the count for another array that we will modify
			if(copyhist[(str[i]-65)]>counter){
				counter = copyhist[(str[i]-65)];
			}
		}
		}
	}
	while(counter>0){
	for(int j=0;j<ALPHABET_SIZE;j++){ //print the tables
		if(counter==copyhist[j]){
			printf("* ");
			copyhist[j]--;
		}else{
			printf("  ");
		}
	}
	counter--;
	printf("\n");
	}
	for(int k=0;k<ALPHABET_SIZE;k++){ //print the occurences
		printf("%d ",st.histo[k]);
	}
	printf("\n");
	for(int l=0;l<ALPHABET_SIZE;l++){ //print the alphabet
		printf("%c ",l+97);
	}
}

/**
 * Update the histogram
 * @param histo	the histogram
 * @param str	the string used to update the histogram
 */
void updateHistogram(int histo[], const char str[])
{
	for(int i=0;str[i];i++){
		if(isalpha(str[i])){
		histo[(str[i]-97)]++; //increases the count for elements that are repeated
		}
	}
}

