/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 2 Question 1
	
	This program finds the answer for C(n,k) when the user inputs n and k while outputting the factorial of n and k.

*/


#include <stdio.h>
#include <math.h>

int main() {

	int c, 
	n, // variable for the first number
	k, // variable for the second number
	z, // variable for the first number minus the second number
	fact1 = 1, // factorial for n
	fact2 = 1, // factorial for k
	fact3 = 1, // factorial for z
	ans; // answer for C(n,k)
 
	// ask the user to input two numbers
	printf("Enter a number: \n");
	scanf("%d", &n);

	printf("Enter another number: \n");
	scanf("%d", &k);
 

	// run the calculations
	if (n < 0 || k < 0) {
		printf("Factorials of negative numbers do not exist.\n");
	} else {

		for (c = 1; c <= n; c++)
			fact1 = fact1 * c;
 
		for (c = 1; c <= k; c++)
			fact2 = fact2 * c;
		
		z = n - k;

		for (c = 1; c <= z; c++)
			fact3 = fact3 * c;

		ans = fact1 / (fact2 * fact3);	

	}
	
	// print all of the answers
	printf("Factorial of %d = %d\n", n, fact1);
 	printf("Factorial of %d = %d\n", k, fact2);
	printf("Factorial of %d - %d = %d\n", n, k, fact3);
	printf("C(n,k) = %d\n", ans);
	

	return 0;
}
