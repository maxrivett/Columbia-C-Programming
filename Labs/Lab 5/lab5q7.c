/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 5 Question 7
	
	This program takes two user-inputted words and outputs the longest common suffix.

*/



#include <stdio.h>

#define MAXLEN 15

int commonSuffixLength(char firstWord[], char secondWord[]);

int main() {

	char w1[MAXLEN]; // first word

	char w2[MAXLEN]; // second word

	//Gets user input
	printf("Please enter a word below:\n");

	scanf("%s", w1);

	printf("Please enter another word below:\n");

	scanf("%s", w2);

	int x = commonSuffixLength(w1, w2);

	

	/*if (w1[x] = '\0') { //This doesn't really work.
		printf("There is no common suffix.");
	} else {*/
		printf("The longest common suffix is \"%s\".\n", &w1[x]);
	//}
	return(0);
}

// Returns the index from which the suffix starts at in firstWord
int commonSuffixLength(char firstWord[], char secondWord[]) {

	int x = 0,
	lastIndex1 = -1,
	lastIndex2 = -1;

	for(int a = 0; a < MAXLEN; a++) {

		if(lastIndex1 == -1 && firstWord[a] == '\0') {

			lastIndex1 = a;

		}

		if(lastIndex2 == -1 && secondWord[a] == '\0') {

			lastIndex2 = a;

		}

	}

	while(firstWord[lastIndex1 - x - 1] == secondWord[lastIndex2 - x - 1]) {

		x++;

	}

	return(lastIndex1 - x);
}
