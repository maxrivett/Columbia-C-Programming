/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 3 Question 3
	
	This program replaced a specified digit in a number that is inputted by the user and replaces it with another number that is inputted by the user.

*/


#include <stdio.h>
#include <math.h>

int replace(int, int, int);
int replaceDigit(int, int, int);
int getDigit(int, int);
int numDigits(int);


int main() {
	int n = 0;
	int oldNum = 0;
	int newNum = 0;

//Gets the numbers from user
	printf("Enter a number, preferably a large number:\n");

	scanf("%d", &n);

	printf("Which digit would you like to replace?\n");

	scanf("%d", &oldNum);

	printf("And with ?\n");

	scanf("%d", &newNum);

	n = replaceDigit(n, oldNum, newNum);

	printf("The new number is %d\n", n);

	return(0);
}

// Precondition: num > 0
// Postcondition: returns num with all instances of oldDigit, but replaced with
// newDigit.
int replaceDigit(int num, int oldDigit, int newDigit) {
	int digitNum = numDigits(num);

	//Finds and replaces old digit with new digits
	for(int a = 1; a <= digitNum; a++) {
		int digit = getDigit(num, a);
		if(digit == oldDigit) {
			num = replace(num, a, newDigit);
		}
	}
	return(num);
}
// Return the index’th digit of num: 
int getDigit(int num, int index) {
	for(int a = 1; a < index; a++) {
		num = num / 10;
	}

	return(num % 10);
}

// Return the number of digits in num: 
int numDigits(int num) {
	int count = 0;

	while(num != 0) {
		num = num / 10;
		count++;
	}

	return(count);
}

//Replaces digit at a specific index with another digit
int replace(int n, int index, int newDigit) {
	int power = pow(10, index - 1);

	int start = n % power;
	int end = n / (power * 10);

	n = start + (newDigit * power) + (end * power * 10);

	return(n);
}
