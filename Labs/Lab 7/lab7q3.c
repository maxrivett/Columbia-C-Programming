/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 7 Question 3
	
	This program takes a user-inputted place on a chess board and outputs all of the possible places a bishop could move from there.

*/


#include <stdio.h>

typedef struct {
	char col;
	int row;
} Position;
void printMoves(Position bishop);
int checkPosition(Position x);

int main(void) {

	Position bishop;

	//User inputs the position of the bishop
	printf("Please enter the postiion of the bishop, make sure the column letter is lowercase. Example: e2 --> ");
	scanf("%c%d", &bishop.col, &bishop.row);
				
	if(checkPosition(bishop)) {

		printMoves(bishop);

	} else {

		printf("That is not a valid postion.\n");

	}

	return(0);
			
}

//Finds which moves are possible and prints them
void printMoves(Position bishop) {

	for(char a = 'a'; a <= 'h'; a = (char)(a + 1)) {

		for(int b = 1; b < 9; b++) {

			if((a - b == bishop.col - bishop.row || a + b == bishop.col + bishop.row) && bishop.col != a) {

				printf("%c%d ", a, b);

			}

		}

	} printf("\n");

}



// Checks position to make sure it stays on the board
int checkPosition(Position x) {

	return(x.col >= 'a' && x.col <= 'h' && x.row > 0 && x.row < 9);

}

