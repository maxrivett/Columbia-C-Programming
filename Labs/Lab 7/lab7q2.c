/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 7 Question 2
	
	This program prompts the user to input the names of authors, a book title, a publisher, and a year of publication. This information is then outputted back to the user.

*/

#include <stdio.h>

#define AUTHORMAXLENGTH 15
#define NAMEMAXLENGTH 100

typedef struct {
	char title[NAMEMAXLENGTH];
	char publisher[NAMEMAXLENGTH];
	int year;
	char authors[AUTHORMAXLENGTH][NAMEMAXLENGTH];
} catalog_entry_t;

int main(void) {

	catalog_entry_t book;

	int x = 0;

	int index = 0;

	//Prompts user to input information
	printf("Please enter the number of authors, must be less than %d --> ", AUTHORMAXLENGTH);

	scanf("%d", &x);

	printf("\n");

	getchar();

	for(int a = 0; a < x; a++) {

		printf("Please enter the name of author number %d --> ", a+1);

		fgets(book.authors[a], NAMEMAXLENGTH, stdin);

		while(book.authors[a][index] != '\n' && index < NAMEMAXLENGTH) {

			index++;

		}

		book.authors[a][index] = '\0';

	}

	printf("\n");	
	
	index = 0;

	char title[NAMEMAXLENGTH];

	char publisher[NAMEMAXLENGTH];

	int year = 0;

	printf("Please enter the book's title --> ");

	fgets(book.title, NAMEMAXLENGTH, stdin);

		printf("\n");
	
	while(book.title[index] != '\n' && index < NAMEMAXLENGTH) {

		index++;

	}

	book.title[index] = '\0';

	index = 0;

	printf("Please enter the name of the publisher --> ");

	fgets(book.publisher, NAMEMAXLENGTH, stdin);

	printf("\n");

	while(book.publisher[index] != '\n' && index < NAMEMAXLENGTH) {

		index++;

	}

	book.publisher[index] = '\0';

	index = 0;

	printf("Please enter the year of publication --> ");

	scanf("%d", &book.year);

	printf("\n");

	//Outputs the data back to the user
	printf("Title: %s\n", book.title);

	printf("Author(s): ");

	for(int a = 0; a < x; a++) {

		printf("%s", book.authors[a]);

		if(a != x - 1) {

			printf(", ");

		}
		
	}

	printf(".");

	printf("\n");

	printf("Publisher: %s\n", book.publisher);

	printf("Publication Year: %d\n", book.year);

	return(0);
}
