/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 1 Question 7
	
	This program is an extension of "Lab 1 Question 6". It takes the inputted data from the user which is how many minutes away from home the user is, and prints the user's estimated arrival time.

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
	int minutesAway; //how far the user is from home
	int ETAmin; //estimated time until home
	int ETAhour;

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
		
	printf("How many minutes from now do you expect to be home?\n");
	scanf("%d", &minutesAway);
	
	ETAmin = min + minutesAway;
	ETAhour = hour;	

	//Calcultes the time when the user will get home
	if (ETAmin >= 60 && ETAmin < 120) {
		ETAmin = ETAmin - 60;
		ETAhour++;
		if (ETAmin < 10) { //in case the minutes number is less that then, it prints with a zero in front of it
			printf("You will get home at %d:0%d. \n", ETAhour, ETAmin);
		}
		if (ETAmin >= 10) {
		printf("You will get home at %d:%d. \n", ETAhour, ETAmin);
		}
	} else
	if (ETAmin < 60) {
		printf("You will get home at %d:%d. \n", hour, ETAmin);
		if (ETAmin < 10) { //in case the minutes number is less that then, it prints with a zero in front of it
			printf("You will get home at %d:0%d. \n", ETAhour, ETAmin);
		}
		if (ETAmin >= 10) {
		printf("You will get home at %d:%d. \n", ETAhour, ETAmin);
		}
	} else
	if (ETAmin >= 120) { //This prevents me from needing to make many more if statements
		printf("You are very far from home.\n");
	} else {
		printf("Insufficient data provided.\n");
	}


	return 0;
}
