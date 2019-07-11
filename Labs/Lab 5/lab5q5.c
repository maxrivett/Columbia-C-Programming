/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 5 Question 5
	
	This program prints a list of names and their respective ages, then prints a list of the names categorized alphabetically, and then numerically.

*/

#include <stdio.h>
#include <string.h>


#define LENGTH 6
#define LONGEST 100


int main() {

	char names[LENGTH][LONGEST] = {"Ryan, Elizabeth", "McIntyre, Osborne", "DuMond, Kristin", "Larson, Lois", "Thorpe, Trinity", "Ruiz, Pedro"};

	int ages[LENGTH] = {62, 84, 18, 42, 15, 35};

	//Original List
	printf("Original List:\n-------------------------\n");

	for(int a = 0; a < LENGTH; a++) {

		printf("%-25s%d\n", names[a], ages[a]);

	}

	for(int a = 0; a < LENGTH; a++) {

		for(int b = 0; b < LENGTH - 1 - a; b++) {

			if(strcmp(names[b], names[b + 1]) > 0) {

				char str_tmp[LONGEST];

				strcpy(str_tmp, names[b]);

				strcpy(names[b], names[b + 1]);

				strcpy(names[b + 1], str_tmp);

				int tmp = ages[b];

				ages[b] = ages[b + 1];

				ages[b + 1] = tmp;

			}

		}

	}
	//List of names in alphabetical order
	printf("\n\nAlphabetized List:\n-------------------------\n");

	for(int a = 0; a < LENGTH; a++) {

		printf("%-25s%d\n", names[a], ages[a]);

	}
	//List of names in order by age
	printf("\n\nNumerical List:\n-------------------------\n");

		printf("%-25s%d\n", names[5], ages[5]);
		printf("%-25s%d\n", names[0], ages[0]);
		printf("%-25s%d\n", names[3], ages[3]);
		printf("%-25s%d\n", names[1], ages[1]);
		printf("%-25s%d\n", names[4], ages[4]);
		printf("%-25s%d\n", names[2], ages[2]);
		printf("\n");

	return(0);
}
