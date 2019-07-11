/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 7 Question 5
	
	This program prompts the user to input number of coils, voltage, and current. The program then outputs the voltage and current in the second coil.

*/

#include <stdio.h>

typedef struct {
	double n1; // number of coils 1
	double n2; // number of coils 2
	double v1; // voltage 1
	double i1; // current 1 (because current is i)
} transformer_t;

//Functions that were asked to be created in the question

//Compute the outpute voltage and current of a transformer
double v_out(transformer_t t);
double i_out(transformer_t t);

//Functions to set the different parts of the transformer to get an output
transformer_t set_c1_for_v2(transformer_t t, double v2);
transformer_t set_v1_for_v2(transformer_t t, double v2);
transformer_t set_c2_for_v2(transformer_t t, double v2);
transformer_t set_c2_for_i2(transformer_t t, double i2);

//Functions to facilitate input/output
transformer_t scan_transformer();
void print_transformer(transformer_t t);

int main() {

	transformer_t t = scan_transformer();

	print_transformer(t);

	return(0);

}

// Returns the output voltage from transformer
double v_out(transformer_t t) {

	return(t.v1 * t.n2 / t.n1);

}

// Returns the output current from transformer
double i_out(transformer_t t) {

	return(t.i1 * t.n1 / t.n2);

}

// Sets the first number of coils n1 in order to get a secondary voltage v2
transformer_t set_n1_for_v2(transformer_t t, double v2) {

	t.n1 = t.v1 * t.n2 / v2;

	return(t);

}

// Sets the primary voltage v1 in order to get a secondary voltage v2
transformer_t set_v1_for_v2(transformer_t t, double v2) {

	t.v1 = v2 * t.n1 / t.n2;

	return(t);

}

// Sets the second number of coils n2 to get a secondary voltage v2
transformer_t set_n2_for_v2(transformer_t t, double v2) {

	t.n2 = v2 * t.n1 / t.v1;

	return(t);

}

//Sets number of secondary coils n2 to get a secondary current i2
transformer_t set_n2_for_i2(transformer_t t, double i2) {

	t.n2 = t.n1 * t.i1 / i2;

	return(t);

}

// Scans input from user
transformer_t scan_transformer() {

	transformer_t t;

	printf("Please enter number of coils in wire 1:\n");

	scanf("%lf", &t.n1);

	printf("Please enter number of coils in wire 2:\n");

	scanf("%lf", &t.n2);

	printf("Please enter the voltage for wire 1:\n");

	scanf("%lf", &t.v1);

	printf("Please enter the current for wire 1:\n");

	scanf("%lf", &t.i1);

	return(t);
}

// Prints the input from the user as well as the voltage and current for wire 2
void print_transformer(transformer_t t) {

	printf("\t\tWire 1\t\t|\tWire 2\n");

	printf("---------------------------------------------------------------------\n");

	printf("No. of Coils:\t%.2lf\t\t|\t%.2lf\n", t.n1, t.n2);

	printf("Voltage:\t%.2lf\t\t|\t%.2lf\n", t.v1, v_out(t));

	printf("Current:\t%.2lf\t\t|\t%.2lf\n", t.i1, i_out(t));

}

