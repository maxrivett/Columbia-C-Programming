/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 6 Question 1
	
	This program takes inputted numbers by the user and outputs those numbers in normal and reverse order.
*/

#include <stdio.h>

void reverseDisplay(int value[], int size);

int main() {

	int size = 0;

	//User inputs the size and numbers to be reversed
	
	printf("What would you like the size of your array to be?:\n");
	scanf("%d", &size);

	int arr[size];

	printf("\n");	
	//For loop that asks the user for numbers until it matches the array size
	for(int a = 0; a < size; a++) {
		printf("Please enter number %d:\n", a + 1);
		scanf("%d", &arr[a]);
	}
	//Print the user's inputted numbers
	printf("\n");
	printf("Your numbers are: ");
	for(int a = 0; a < size; a++) {
		printf("%d ", arr[a]);
	}
	//Print the user's inputted numbers in reverse order
	printf("\n\n");
	printf("Your numbers in reverse order are: ");
	reverseDisplay(arr, size);
	printf("\n\n");

	return(0);

}



void reverseDisplay(int value[], int size) {
	//Recursion
	if (size == 1) {
		printf("%d", value[size - 1]);
	} else {
		printf("%d ", value[size - 1]);
		reverseDisplay(value, size - 1);
	}
	

}


