/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 6 Question 4
	
	This program returns the value of the definition f(x) = f(x - 1) + 2 unless x is equal or less than zero in which case the program returns 0.

*/

#include <stdio.h>

double f(double x);

int main() {

	double x = 0;

	printf("Enter value of x:\n");

	scanf("%lf", &x);

	double answer = f(x);

	printf("The value of f(x) is %lf.\n", answer);

	return(0);
}

//f(x) returns 2x because f(x - 1) + 2 is equal to f(x) unless it is a decimal
double f(double x) {

	if(x <= 0) {

		return(0);

	} else {

		return(f(x-1) + 2);

	}
}
