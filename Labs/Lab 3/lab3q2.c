/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 3 Question 2
	
	This program adds the digits of the number that the user inputs until it becomes a one-digit number, which is then outputted.

*/

#include <stdio.h>

int sumDigits(int);
int getDigit(int, int);
int numDigits(int);

int main() {

	int num = 0;

	//Ask the user to input a number
	printf("Enter a number, preferably a large number:\n");
	scanf("%d", &num);

	//Checks if the inputted number is valid
	if(num <= 0) {
		printf("That is not a valid input.\n");
	} else {
		while(num > 9) {
			num = sumDigits(num);
		}
	}

	printf("The final sum of the digits is: %d.\n", num);

	return(0);
}

// Precondition: num > 0 
// Postcondition: the return value is the iterated sum of digits of num 

int sumDigits(int n) {
	int digitsNum = numDigits(n);
	int sum = 0;

	for(int i = 1; i <= digitsNum; i++) {
		int digit = getDigit(n, i);
		sum += digit;
	}

	return(sum);
}


// Return the index’th digit of num: 
int getDigit(int n, int index) {
	for(int i = 1; i < index; i++) {
		n = n / 10;
	}

	return(n % 10);
}

// Return the number of digits in num: 
int numDigits(int n) {
	int count = 0;

	while(n != 0) {
		n = n / 10;
		count++;
	}

	return(count);
}
