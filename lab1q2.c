/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 1 Question 2
	
	This program finds whether or not the letter that the user inputs is uppercase or lowercase.

*/


#include <stdio.h>

char main(void) {
	char letter; // the letter that the user inputs

	// Get the letter
	printf("Enter a letter, it can be upper or lower case:\n");
	scanf("%c", &letter);

	//Finding if it is uppercase
	if (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F' || letter == 'G' || letter == 'H' || letter == 'I' || letter == 'J' || letter == 'K' || letter == 'L' || letter == 'M' || letter == 'N' || letter == 'O' || letter == 'P' || letter == 'Q' || letter == 'R' || letter == 'S' || letter == 'T' || letter == 'U' || letter == 'V' || letter == 'W' || letter == 'X' || letter == 'Y' || letter == 'Z') {
		printf("The letter is uppercase.\n"); 
	} else //Finding if it is lowercase
	if (letter == 'a' || letter == 'b' || letter == 'c' || letter == 'd' || letter == 'e' || letter == 'f' || letter == 'g' || letter == 'h' || letter == 'i' || letter == 'j' || letter == 'k' || letter == 'l' || letter == 'm' || letter == 'n' || letter == 'o' || letter == 'p' || letter == 'q' || letter == 'r' || letter == 's' || letter == 't' || letter == 'u' || letter == 'v' || letter == 'w' || letter == 'x' || letter == 'y' || letter == 'z') {
		printf("The letter is lowercase.\n");
	} else { //Printing that it isn't a letter
		printf("That is not a letter.\n");
	}
	return 0;
}
