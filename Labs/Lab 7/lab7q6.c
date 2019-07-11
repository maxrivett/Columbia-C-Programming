/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 7 Question 6
	
	This program calculates how long a battery could operate an 8A device for, before and after recharging the battery.

*/

#include <stdio.h>


typedef struct {
	double emf;
	double max_energy;
	double current_energy;
} battery_t;

//Facilitates IO of battery
battery_t scan_battery();
void print_battery(battery_t x);

//Other methods to interact with battery_t
int power_device(double current, double time, battery_t *x);
double max_time(battery_t x, double current);
battery_t recharge(battery_t x);

int main() {

	battery_t battery = {12, 5000000, 5000000}; // 12V battery with a maximum energy storage of 5 x 10^6J

	int bool = power_device(4, 15 * 60, &battery); // powers a 4A light for 15 minutes

	double t1 = max_time(battery, 8); // amount of time it could power an 8A device for

	battery = recharge(battery); // battery after powering the light and recharging it

	double t2 = max_time(battery, 8); // amount of time it could power an 8A device for

	//scan_battery();

	//print_battery(battery_t x);

	printf("Before recharging it, the battery could power the 8A device for a total of %lf seconds.\n", t1);

	printf("\n");

	printf("After recharging it, the battery could power the 8A device for a total of %lf seconds.\n", t2);

	return(0);

}
/*
// Scans user input
battery_t scan_battery() {

	battery_t x;

	printf("Please enter the EMF (electomagnetic field) of the battery:\n");

	scanf("%lf", &x.emf);

	printf("Please enter the energy capacity of the battery:\n");

	scanf("%lf", &x.max_energy);

	printf("Please enter the current energy level of the battery:\n");

	scanf("%lf", &x.current_energy);

	return(x);

}

// Prints the user's input back
void print_battery(battery_t x) {

	printf("The EMF of the battery is %lf.\n", x.emf);

	printf("The energy capacity of the battery is %lf.\n", x.max_energy);

	printf("The current energy level of the battery is %lf.\n", x.current_energy);

}
*/
//subtracts required energy from b if b has enough battery  and returns 1 else does nothing and returns 0
int power_device(double current, double time, battery_t *x) {

	if(max_time(*x, current) >= time) {

		x -> current_energy -= x->emf * current * time;

		return(1);

	} else {

		return(0);

	}

}

double max_time(battery_t x, double current) {

	double time = x.current_energy / (x.emf * current);

	return(time);

}

battery_t recharge(battery_t x) {

	x.current_energy = x.max_energy;

	return(x);

}
