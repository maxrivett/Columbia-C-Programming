/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 1 Question 5
	
	This program allows the user to input a month and year, and the program returns the number of days in the specified month.

*/


#include <stdio.h>

int main(void) {
	int year, // the year inputted by user
	month, // the month inputted by user
	days; // the days in the month

	// Input the month 
	printf("Please enter a number that represents a month. For instance, January is 1, February is 2, etc.:\n");
	scanf("%d", &month);
	// Input the year
	printf("Please enter a year:\n");
	scanf("%d", &year);
	// Find the number of days
	if (month == 1) {
		printf("January %d has 31 days.\n", year);
	} else
	if (month == 2 && year % 4 == 0) {
		printf("February %d has 29 days.\n", year);
	} else
	if (month == 2 && year % 4 != 0) {
		printf("February %d has 28 days.\n", year);
	} else
	if (month == 3) {
		printf("March %d has 31 days.\n", year);
	} else
	if (month == 4) {
		printf("April %d has 30 days.\n", year);
	} else
	if (month == 5) {
		printf("May %d has 31 days.\n", year);
	} else
	if (month == 6) {
		printf("June %d has 30 days.\n", year);
	} else
	if (month == 7) {
		printf("July %d has 31 days.\n", year);
	} else
	if (month == 8) {
		printf("August %d has 31 days.\n", year);
	} else
	if (month == 9) {
		printf("September %d has 30 days.\n", year);
	} else
	if (month == 10) {
		printf("October %d has 31 days.\n", year);
	} else
	if (month == 11) {
		printf("November %d has 30 days.\n", year);
	} else
	if (month == 12) {
		printf("December %d has 31 days.\n", year);
	} else {
		printf("Invalid inputs.\n");
	} 
	
	return 0;
}
