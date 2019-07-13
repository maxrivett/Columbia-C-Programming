/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 8 Question 4
	
	This program takes words from a text file and prints each one on a separate line of an output file followed by the number of letters in the word. 

*/

#include <stdio.h>

#define MAXLENGTH 100

void printWord(FILE *output, char word[MAXLENGTH]);

int isChar(char a);

int wordLength(char word[MAXLENGTH]);

int main(void) {

	char inName[MAXLENGTH];
	char outName[MAXLENGTH];

	printf("Please enter your input file's name, make sure it has at least a few words:\n");
	scanf("%s", inName);

	printf("Please enter the file's name in which you would like to store the output:\n");
	scanf("%s", outName);

	FILE *input = fopen(inName, "r");
	FILE *output = fopen(outName, "w");

	char word[MAXLENGTH];

	int checkEOF = fscanf(input, "%s", word);

	while(checkEOF != EOF) {

		printWord(output, word);

		checkEOF = fscanf(input, "%s", word);

	}

	printf("Your data has successfully been transferred from \"%s\" to \"%s\".\n", inName, outName);

	fclose(input);
	fclose(output);

	return 0;
}

void printWord(FILE *output, char word[MAXLENGTH]) {

	int len = wordLength(word);

	while(!isChar(word[0])) {

		for(int a = 1; a < MAXLENGTH; a++) {

			word[a - 1] = word[a];

		}

	}

	int x = 0;

	while(word[x] != '\0') {

		x++;

	}

	while(x != 0 && !isChar(word[x])) {

		word[x] = '\0';

		x--;

	}

	fprintf(output, "%s - %d\n", word, len);

}

int isChar(char a) {

	return((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'));

}

int wordLength(char word[MAXLENGTH]){

	int x = 0;

	for(int a = 0; a < MAXLENGTH && word[a] != '\n' && word[a] != ' ' && word[a] != '\0'; a++) {

		if(isChar(word[a])) {

			x++;

		}

	}

}


