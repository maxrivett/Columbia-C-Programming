/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 7 Question 1
	
	This program prompts the user to input longitude and latitude data, then outputs and compares the data.
*/
#include <stdio.h>

typedef struct {
	int degrees;
	int minutes;
	char direction;
} long_lat_t;

long_lat_t scan_long_lat(long_lat_t x);

void print_long(long_lat_t x);
void print_lat(long_lat_t x);

int long_lat_equal(long_lat_t a, long_lat_t b);

int main() {

	long_lat_t a,
	b;

	printf("Longitude:\n");

	a = scan_long_lat(a);
	
	printf("\n");
	printf("Latitude:\n");

	b = scan_long_lat(b);

	printf("\n");
	printf("Longitude:\n");

	print_long(a);
	printf("\n");		

	printf("Latitude:\n");

	print_lat(b);
	
	printf("\n");
	int longlatequal = long_lat_equal(a, b);

	//Checks the values from long_lat_equal
	if(longlatequal) {

		printf("The longitude and latitude are equal.\n");

	} else {

		printf("The longitude and latitude are not equal.\n");

	}

	printf("\n");	

	return(0);
}

//Gets the longitude and latitude data
long_lat_t scan_long_lat(long_lat_t x) {

	printf("Please enter the degrees below:\n");

	scanf("%d", &(x.degrees));

	printf("Please enter the minutes below:\n");

	scanf("%d", &(x.minutes));

	printf("Please enter the direction below:\n");

	scanf(" %c", &(x.direction));

	return(x);
}

//Prints inputted longitude data
void print_long(long_lat_t x) {

	printf("The longitude data:\n");

	printf("Degrees:\t%d\nMinutes:\t%d\nDirection:\t%c\n", x.degrees, x.minutes, x.direction);

}

//Prints inputted latitude data
void print_lat(long_lat_t x) {

	printf("The latitude data:\n");

	printf("Degrees:\t%d\nMinutes:\t%d\nDirection:\t%c\n", x.degrees, x.minutes, x.direction);

}

//If the degrees, minutes, and direction of "a" are equal to the degrees, minutes, and direction of "b", 1 is returned, otherwise 0.
int long_lat_equal(long_lat_t a, long_lat_t b) {

	if(a.degrees == b.degrees && a.minutes == b.minutes && a.direction == b.direction) {

		return(1);

	} else {

		return(0);

	}

}
