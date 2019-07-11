/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 5 Question 2
	
	This program prompts the user to input an integer from 0 to 9. With that integer, the program writes a factorial equation that is outputted within a box of asterisks.
*/

#include <stdio.h>

int n,
equationlen;

void fact_calc(int numin);

void fact_calc(int numin) {

	int result = numin;
	int fact = 1;

	for (int a = 1; a <= n; a++) {
		fact = fact * a;
	}
	
	char equation[equationlen];

	if (numin < 10) {

	for (int a = 0; a < numin * 4 + 10; a++) {
		
		printf("*");
		
	
	}
	
	//Makes sure the proper number of asterisks are printed for each box	
	if (numin > 3) {
		printf("*");
	}
	if (numin > 4) {
		printf("*");
	}
	if (numin > 6) {
		printf("*");
	}
	if (numin > 7) {
		printf("*");
	}
	if (numin > 8) {
		printf("*");
	}
	

	printf("\n* %d! = %d", numin, numin);
	
	

	for (int a = numin - 1; a > 0; a--) {\
	
		result = result * a;
		printf(" x %d", a);

	}
	
	printf(" = %d *\n", result);

	for (int a = 0; a < numin * 4 + 10; a++) {
		
		printf("*");
	
	}
	//Makes sure the proper number of asterisks are printed for each box	
	if (numin > 3) {
		printf("*");
	}
	if (numin > 4) {
		printf("*");
	}
	if (numin > 6) {
		printf("*");
	}
	if (numin > 7) {
		printf("*");
	}
	if (numin > 8) {
		printf("*");
	}

	} else {
		printf("\nYour number must be from 1 to 9, and your number, \"%d\", is not.\n", numin);
	}

}


int main(void) {

	int n,
	equationlen;


		
	printf("This program will continue until you choose to end it, in which case enter -1.\n\n");
	printf("Please enter a number from 0-9:\n");
	scanf("%d", &n);

	while (n != -1) {

		fact_calc(n);

		printf("\n\nPlease enter another number from 0-9:\n\n");
		scanf("%d", &n);

		
	}



}


