/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 5 Question 1
	
	This program takes the inputted sentence from a user and outputs the same sentence but without the spaces.
*/

#include <stdio.h>
#include <string.h>
#define MAXSTRING 100

char *deblank(char *input) {

	char *output = input;
	
	for (int a = 0, b = 0; a < strlen(input); a++, b++) {
		
		if (input[a] != ' ') {
	
			output[b] = input[a];
		
		} else {

			b--;
		
		}
	
	}
		
	return output;

}

int main(void) {

	char input[MAXSTRING];
	char end[] = "END\n";
	
	printf("This program will continue until you choose to end it, in which case press control+C.\n\n");
	printf("Please enter a sentence:\n");
	fgets(input, MAXSTRING, stdin);

	while (strcmp(input, end) != 0) {
		
		
	
		input[strlen(input) - 1] = '\0';
		printf("Your original sentence was: \"%s\"\n", input);
		printf("Your new sentence is: \"%s\"\n", deblank(input));
		
		printf("Please enter another sentence:\n");
		fgets(input, MAXSTRING, stdin);
	}

	

}


