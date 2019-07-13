/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 8 Question 1
	
	This program prompts the user to input the name of two text files, both of which include a line with an int atomic number followed by the element name, chemical symbol, and the atomic weight. The program will then combine the two text files and store their data in a new file that the user chooses. 

*/

#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 118 // because there are 118 elements in the periodic table
#define MAX_LENGTH 100

int fillElements(FILE *input, char array[MAX_ELEMENTS][MAX_LENGTH]);

int mergeArray(char arr1[MAX_ELEMENTS][MAX_LENGTH], char arr2[MAX_ELEMENTS][MAX_LENGTH], char arr3[MAX_ELEMENTS][MAX_LENGTH], int b1, int b2);

void fillFile(FILE *output, char arr[MAX_ELEMENTS][MAX_LENGTH], int l);

char *scan_line(char *dest, FILE* input, int dest_len);

int main() {

	char nameIn1[MAX_LENGTH];

	char nameIn2[MAX_LENGTH];

	char nameOut[MAX_LENGTH];

	printf("Please enter name of first input file:\n");

	scanf("%s", nameIn1);

	printf("Please enter name of second input file:\n");

	scanf("%s", nameIn2);

	printf("Please enter name of output file:\n");

	scanf("%s", nameOut);

	FILE *input1 = fopen(nameIn1, "r");

	FILE *input2 = fopen(nameIn2, "r");

	FILE *output = fopen(nameOut, "wb");

	char textIn1[MAX_ELEMENTS][MAX_LENGTH];

	char textIn2[MAX_ELEMENTS][MAX_LENGTH];

	int length1 = fillElements(input1, textIn1);

	int length2 = fillElements(input2, textIn2);

	fclose(input1);

	fclose(input2);

	char textOut[MAX_ELEMENTS][MAX_LENGTH];

	int lengthOut = mergeArray(textIn1, textIn2, textOut, length1, length2);

	fillFile(output, textOut, lengthOut);

	fclose(output);

	printf("Your data has been successfully transferred!\n");

	printf("Your data that is now in the binary file \"%s\":\n", nameOut);

	output = fopen(nameOut, "rb");

	char textOut2[MAX_ELEMENTS][MAX_LENGTH];

	for (int a = 0; a < lengthOut; a++) {

		fread(textOut2[a], sizeof(char), MAX_LENGTH, output);

		printf("%s", textOut2[a]);

	}

	fclose(output);

	return(0);

}

//Fills the 2d array array with lines from FILE *input
//Returns the length of the array
int fillElements(FILE *input, char array[MAX_ELEMENTS][MAX_LENGTH]) {

	int length = 0;

	for(int a = 0; a < MAX_ELEMENTS; a++) {

		scan_line(array[a], input, MAX_LENGTH);

		length++;

		if(array[a][0] == '\0') {

			break;

		}

	}

	length--;

	return(length);
}


//Merges the first and second array into the third array and keeps it sorted
////Returns the length of the third array
int mergeArray(char arr1[MAX_ELEMENTS][MAX_LENGTH], char arr2[MAX_ELEMENTS][MAX_LENGTH], char arr3[MAX_ELEMENTS][MAX_LENGTH],int b1, int b2) {

	int a1 = 0,
	a2 = 0;

	for(int a = 0; a < b1 + b2; a++) {

		if(a1 >= b1) {

			strcpy(arr3[a], arr2[a2]);

			a2++;

		} else if(a2 >= b2) {

			strcpy(arr3[a], arr1[a1]);

			a1++;

		} else {

			int num1 = 0;

			int num2 = 0;

			sscanf(arr1[a1], "%d", &num1);

			sscanf(arr2[a2], "%d", &num2);

			if(num1 < num2) {

				strcpy(arr3[a], arr1[a1]);

				a1++;

			} else {

				strcpy(arr3[a], arr2[a2]);

				a2++;

			}

		}

	}

	return(b1 + b2);
}

//Fills output with the values in arr
void fillFile(FILE *output, char arr[MAX_ELEMENTS][MAX_LENGTH], int b) {

	for(int a = 0; a < b; a++) {

		sprintf(arr[a], "%s\n", arr[a]);

		fwrite(arr[a], sizeof(char), MAX_LENGTH, output);

	}

}

// Mr. Pajela's Code
/* * Gets one line of data from input. Returns an empty string on * end of file. If data line will not fit in allotted space, stores * portion that does fit and discards rest of input line. */
char *scan_line(char *dest, FILE* input, int dest_len) {

	int i, ch;  // Gets next line one character at a time.

	i = 0;

	for (ch = getc(input); ch != '\n' && ch != EOF && i < dest_len - 1; ch = getc(input)) {

		dest[i++] = ch;

	}

	dest[i] = '\0';  // Discards any characters that remain on input line 

	while (ch != '\n' && ch != EOF) {

		ch = getc(input);

	}

	return(dest);
}
