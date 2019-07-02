/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 1 Question 3
	
	This program tells the user which level of schooling they are in based off of the number of years that they input.

*/


#include <stdio.h>

int main(void) {
	double y; // the number that the user inputs

	// Get the number of years at school
	printf("How many years have you been in school?:\n");
	scanf("%lf", &y);

	if (y == 0) {
		printf("You have not been to school.\n");
	} else 
	if (y >= 1 && y <= 5) {
		printf("You are in elementary school.\n");
	} else 
	if (y >= 6 && y <= 8) {
		printf("You are in middle school.\n");
	} else 
	if (y >= 9 && y <= 12) {
		printf("You are in high school.\n");
	} else 
	if (y > 12) {
		printf("You are in college/university.\n");
	} else {
		printf("You have given insufficient data.\n");
	}
	
	return 0;
}
	
	
