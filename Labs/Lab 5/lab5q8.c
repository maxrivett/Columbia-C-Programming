/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 5 Question 8
	
	This program transfers names from on file to another, and separates different parts of the names which are then sorted into columns.

*/

#include <stdio.h>

#define FILENAMEMAXLENGTH 100
#define LINEMAXLENGTH 80

char *scan_line(char *dest, FILE* input, int dest_len);

void cutName(char line[LINEMAXLENGTH], char surname[15], char first[10], char middle_init[2]);

int main() {
	
	FILE *output;	
	
	FILE *input;

	char nameOut[FILENAMEMAXLENGTH],
	nameIn[FILENAMEMAXLENGTH];

	//Prompts the user to input the names of the files
	printf("Please enter your input file name: \n");

	scanf("%s", nameIn);

	printf("Please enter your output file name: \n");

	scanf("%s", nameOut);

	input  = fopen(nameIn, "r");

	output = fopen(nameOut, "w");

	char start = 'a';

	do {

		char surname[15];

		char first[10];

		char middle_init[2];

		char line[LINEMAXLENGTH];

		scan_line(line, input, LINEMAXLENGTH);

		start = line[0];

		if(line[0] == '\0') {

			break;

		} else {

			cutName(line, surname, first, middle_init);

		}

		fprintf(output, "%-15s   %-10s   %-1s\n", surname, first, middle_init);

	} while(start != '\0');

	fclose(input);

	fclose(output);

	printf("Your data has been transferred.\n\n");

	return(0);
}

//Mr. Pajela's code (scan_line)
char *scan_line(char *dest, FILE* input, int dest_len) {

	int a = 0, 
	chr; //Basically gets the next line one character at a time 

	for (chr = getc(input); chr != '\n' && chr != EOF && a < dest_len - 1; chr = getc(input)) {

		dest[a++] = chr;

	}

	dest[a] = '\0';  /* Discards any characters that remain on input line */

	while (chr != '\n' && chr != EOF) {

		chr = getc(input);

	}

	return(dest);

}

//The name is split into the three different arrays
void cutName(char line[LINEMAXLENGTH], char surname[15], char first[10], char middle_init[2]) {

	int lineNumber = 0,
	surnameNumber = 0,
	firstNumber = 0;

	while(line[lineNumber] != ',' && surnameNumber < 15) {

		surname[surnameNumber] = line[lineNumber];

		surnameNumber++;

		lineNumber++;

	}

	surname[surnameNumber] = '\0';


	while(line[lineNumber] != ',') {

		lineNumber++;

	}

	lineNumber += 2;

	while(line[lineNumber] != '.' && line[lineNumber] != ' ' && firstNumber < 10) {

		first[firstNumber] = line[lineNumber];

		firstNumber++;

		lineNumber++;

	}

	first[firstNumber] = '\0';


	while(line[lineNumber] != '.' && line[lineNumber] != ' ') {

		lineNumber++;

	}

	if(line[lineNumber] == '.') {

		lineNumber += 2;

	} else {

		lineNumber += 1;

	}

	middle_init[0] = line[lineNumber];

	middle_init[1] = '\0';
}
