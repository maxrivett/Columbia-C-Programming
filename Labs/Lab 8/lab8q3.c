/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 8 Question 3
	
	This program takes input from the user and either converts a text file from traditional matrix to sparse matrix, or vice versa.

*/

#include <stdio.h>

FILE *in, *out;
int scan_matrix(FILE *f, FILE *o);
int write_sparse(FILE *o, int row, int col, int x);
int scan_sparse(FILE *f, FILE *o);
int write_matrix(FILE *o, int x);


int main(void) {

	char choice;	

	printf("Would you like to convert from traditional matrix to sparse matrix or vice versa? If you would like to convert FROM traditional type \"a\", if you would like to convert FROM sparse type \"b\".\n");
	scanf("%c", &choice);

	// If user chooses to convert from traditional
	if (choice == 'a' || choice == 'A') {

		in = fopen("matrix.txt", "r");

		out = fopen("sparse.txt", "a");

		scan_matrix(in, out);

		printf("\n\t\tProcess complete.\n\n");

	// If user chooses to convert from sparse
	} else if (choice == 'b' || choice == 'B') {

		in = fopen("sparse.txt", "r");

		out = fopen("matrix.txt", "a");

		scan_sparse(in, out);	

		printf("\n\t\tProcess complete.\n\n");

	// If the user doesn't follow instructions
	} else {

		printf("\n\t\tYou didn't follow the incredibly simple guidelines. Please try again.\n\n");

	}

}

int scan_matrix(FILE *f, FILE *o) {

	int s1, 
	s2;

	fscanf(f, "%d %d", &s1, &s2);

	int matrix[s1][s2];

	fprintf(o, "%d %d\n", s1, s2);

	for(int a = 0; a < s1;a++) {

		for(int b = 0; b < s2; b++) {

			fscanf(f, "%d", &matrix[a][b]);

			write_sparse(o, a, b, matrix[a][b]);

		}

	}

}

int write_sparse(FILE *o, int row, int col, int x) {

	if(x != 0) {
		fprintf(o, "%d %d %d\n", row, col, x);

	}

}

int scan_sparse(FILE *f, FILE *o) {

	int s1, 
	s2;

	fscanf(f, "%d %d", &s1, &s2);

	int matrix[s1][s2];

	fprintf(o, "%d %d\n", s1, s2);

	int x, y, z;

	for(int a = 0; a < s1; a++) {

		for(int b = 0; b < s2; b++) {

			matrix[a][b] = 0;

		}

	}

	for(int a = 0; a < s1 * s2; a++) {

			fscanf(f, "%d %d %d", &x, &y, &z);

			matrix[x][y]= z;

	}

	for(int a = 0; a < s1; a++) {

		for(int b = 0; b < s2; b++) {

			write_matrix(o, matrix[a][b]); 

		}

		fprintf(o, "\n");

	}

}
int write_matrix(FILE *o, int x) {

	fprintf(o, "%d ", x);

}


