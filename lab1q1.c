/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 1 Question 1
	
	This program prompts the user to input three numbers and discerns whether or not the third number is between the first two.

*/


#include <stdio.h>

int main(void) {
	int number1, // the first of the three numbers the user inputs
		number2, // the second of the three numbers the user inputs
		number3; // the third of the three numbers the user inputs

	// Get the first number
	printf("Enter a number:\n");
	scanf("%d", &number1);

	// Get the second number
	printf("Enter another number:\n");
	scanf("%d", &number2);

	// Get the third number
	printf("Enter a final number:\n");
	scanf("%d", &number3);

	//Find if the third number is between the first and second number
	if (number1 < number3 && number3 < number2 || number2 < number3 && number3 < number1) {
		printf("The third number is strictly between the first and second number.\n"); // Prints that it is in between
	} else {
		printf("The third number is not between the first and second number.\n"); //Prints that it is not
	}

	return 0;
}
