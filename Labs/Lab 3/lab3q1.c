/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 3 Question 1
	
	This program prompts the user to input three numbers, and then outputs the three numbers in decreasing order.

*/


#include <stdio.h>
#include <math.h>

void sort(double num1, double num2, double num3);


int main() {

	
	double a, 
	b,
	c,
	num1,
	num2,
	num3;

	
	
//User inputs three numbers
	printf("Enter the first of three integers:\n");
	scanf("%le", &num1);
	
	printf("Enter the second of three integers:\n");
	scanf("%le", &num2);
		
	printf("Enter the third of three integers:\n");
	scanf("%le", &num3);


	sort(num1, num2, num3);
	return 0;

} 

void sort(double num1, double num2, double num3) {


//Many if statements decide which order the numbers must go in, and print it
	if (num1 > num2 && num2 > num3) {
		printf("The decreasing order is %3.0f, %3.0f, %3.0f\n", num1, num2, num3);
	} else
	if (num1 > num3 && num3 > num2) {
		printf("The decreasing order is %3.0f, %3.0f, %3.0f\n", num1, num3, num2);
	} else
	if (num2 > num1 && num1 > num3) {
		printf("The decreasing order is %3.0f, %3.0f, %3.0f\n", num2, num1, num3);
	} else
	if (num2 > num3 && num3 > num1) {
		printf("The decreasing order is %3.0f, %3.0f, %3.0f\n", num2, num3, num1);
	} else
	if (num3 > num2 && num2 > num1) {
		printf("The decreasing order is %3.0f, %3.0f, %3.0f\n", num3, num2, num1);
	} else
	if (num3 > num1 && num1 > num2) {
		printf("The decreasing order is %3.0f, %3.0f, %3.0f\n", num3, num1, num2);
	} 

}

