/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 6 Question 2
	
	This program prompts the user to input a set of 8 integers and then outputs the smallest integer of the eight.
*/

#include <stdio.h>

#define min(x, y) (x) < (y) ? (x) : (y)

int smallestint(int arr[], int last_index);

int main() {
	
	int size = 8; //Because list is composed of 8 ints
	int arr[size]; //I could've just said 8 instead of size but it looks better this way

	//User inputs 8 integers
	for(int a = 0; a < size; a++) {

		printf("Please enter number %d: ", a + 1);

		scanf("%d", &arr[a]);

		printf("\n");

	}

	int s = smallestint(arr, size - 1);

	printf("The smallest number of the eight is:  %d\n", s);

	return(0);

	printf("\n");
}

int smallestint(int arr[], int finalNum) {

	if(finalNum == 0) {

		return(arr[0]);

	} else {

	return(min(arr[finalNum], smallestint(arr, finalNum - 1)));

	}
}
