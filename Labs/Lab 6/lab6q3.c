/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 6 Question 3
	
	This program asks the user to input ten integers and then an integer that they would like to be counted. The program outputs the amount of times that the integer that was counted was inputted by the user.

*/

#include <stdio.h>

#define SIZE 10

int count(int ints[], int num, int size);

int main() {

	int size = 10; 
	int arr[size];
	int num;
	
	printf("You will be asked to input ten integers.\n");

	//For loop that asks the user for numbers until it matches the array size
	for(int a = 0; a < size; a++) {
		printf("Please enter number %d:\n", a + 1);
		scanf("%d", &arr[a]);
	}
	//User chooses which integer they want to be counted
	printf("Choose the number which you would like the program to count:\n");	
	
	scanf("%d", &num);

	printf("The number of %ds in the array is %d.\n", num, count(arr, num, SIZE));

	return(0);
}

int count(int ints[], int num, int size) {

	if(size <= 0) {

		return(0);

	} else {

		if(ints[size - 1] == num) {

			return(count(ints, num, size - 1) + 1);

		} else {

			return(count(ints, num, size - 1));
		}
	}
}
