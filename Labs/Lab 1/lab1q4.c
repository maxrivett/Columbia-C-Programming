/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 1 Question 4
	
	This program allows the user to find the volume of a sphere or a cube, using the radius or side length of their choosing.

*/


#include <stdio.h>
#define PI 3.14159 /* conversion constant */

int main(void) {
	double volumeCube, // the volume of the cube
	volumeSphere, // the volume of the sphere
	side, // the length of the sides of the cube
	radius; // the radius of the sphere
	char shape; // choice of cube or sphere

	// Get the shape wanted
	printf("Would you like to find the volume of a cube or a sphere? Enter 'C' for cube or 'S' for sphere:\n");
	scanf("%c", &shape);

	if (shape == 'C' || shape == 'c') { //Finds the volume of the cube
		printf("What is the length of a side of the cube?\n");
		scanf("%le", &side);
		
		volumeCube = side * side * side;
		printf("The volume of the cube is %5.1f units cubed.\n", volumeCube);
	} else 
	if (shape == 'S' || shape == 's') { //Finds the volume of the sphere
		printf("What is the radius of the sphere?\n");
		scanf("%le", &radius);
		
		volumeSphere = 1.333 * PI * radius;
		printf("The volume of the sphere is %5.1f units cubed.\n", volumeSphere);
	} else { //If the user inputs characters that can't be used
		printf("Invalid number\n");
	}

	
	return 0;
}
