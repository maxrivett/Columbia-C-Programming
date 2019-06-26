/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 1 Question 6
	
	This program takes the inputted sunset time data from the user and determines whether it is mornin, afternoon, or evening. I also added on a feature that reads out the current time.

*/


#include <stdio.h> 
#include <time.h>

int main(void) {
	time_t t;
	struct tm *now;
	t = time(0); //get current time
	now = localtime(&t); //adjust for local timezone
	int hour = now->tm_hour; //retrieve current hour
	int min = now->tm_min; //retrieve the current minute
	int sunsetHour; //user-inputted hour of sunset
	int sunsetMinute; //user-inputted minute of sunset
	

	//Asking the user when the sun sets
	printf("What is the sunset hour tonight? (In 24-hour time):\n");
	scanf("%d", &sunsetHour);
	
	printf("What is the sunset minute tonight?:\n");
	scanf("%d", &sunsetMinute);
	
	
	//Calculates whether it is morning, afternoon, or evening
	if (hour >= 0 && hour <= 11) {
		printf("Good morning.\n");
		printf("The current time is %d:%d.\n", hour, min);
	} else
	if (hour >= 12 && hour < sunsetHour) {
		printf("Good afternoon.\n"); 
		printf("The current time is %d:%d.\n", hour, min);
	} else
	if (hour == sunsetHour && min <= sunsetMinute) {
		printf("Good afternoon.\n"); 
		printf("The current time is %d:%d.\n", hour, min);
	} else
	if (hour >= sunsetHour && hour < 24) {
		printf("Good evening.\n");
		printf("The current time is %d:%d.\n", hour, min);
	} else
	if (hour == sunsetHour && min > sunsetMinute) {
		 printf("Good evening.\n");
		printf("The current time is %d:%d.\n", hour, min);
	} else {
		printf("Insufficient data provided.\n");
	}
			
	
	return 0;
}
