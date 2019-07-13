/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 8 Question 2
	
	This program allows the user to either input or access data on airplanes stored in a file of their choosing.

*/

#include <stdio.h>
#include <string.h>

typedef struct {
	char name[25];
	int cruiseSpeed;
	double wingspan;
	double length;
	char type[3];
	char descrip[50];
} data;


int main() {

	char databaseName[50];

	data plane;

	char c;

	printf("Would you like to input or access data? [I/A]");

	scanf("%c", &c);

	// If the user chooses to input
	if(c == 'I' || c == 'i') {

		printf("Please enter the name of the Database:\n");

		scanf("%s", databaseName);

		FILE *db = fopen(databaseName, "rb");

		printf("Please enter the aircraft's name:\n");
		scanf("%s", &plane.name);
		
		printf("Please enter the aircraft's maximum cruise speed:\n");
		scanf("%d", &plane.cruiseSpeed);
		
		printf("Please enter the aircraft's wingspan:\n");
		scanf("%lf", &plane.wingspan);
	
		printf("Please enter the aircraft's length:\n");
		scanf("%lf", &plane.length);
		
		printf("Please enter the aircraft's type - Military(M) or Civilian(C):\n");
		scanf("%s", &plane.type);
		
		printf("Please enter the a brief description of the aircraft that is no longer than 50 characters:\n"); 
		scanf("%s", &plane.descrip);
		
		


		char temp[10];
		snprintf(temp, 10, "%d", plane.cruiseSpeed);

		char temp2[10];
		snprintf(temp2, 10, "%lf", plane.wingspan);

		char temp3[10];
		snprintf(temp3, 10, "%lf", plane.length);

		fwrite(plane.name, 1, sizeof(plane.name), db);

		fwrite(temp, 1, sizeof(temp), db);

		fwrite(temp2, 1, sizeof(temp2), db);	
	
		fwrite(temp3, 1, sizeof(temp3), db);	
	
		fwrite(plane.type, 1, sizeof(plane.type), db);	
	
		fwrite(plane.descrip, 1, sizeof(plane.descrip), db);

	// If the user chooses to access
	} else if (c == 'A' || c == 'a') {

		printf("Please enter the name of the Database:\n");

		scanf("%s", databaseName);

		FILE *db = fopen(databaseName, "rb");

		int x = 1;
		char temp[10],
		temp2[10],
		temp3[10],
		temptest[10] = "          ";

		while(x == 1)	{

			fread(&plane.name, 25, 1, db);

			fread(temp, 10, 1, db);

			fread(temp2, 10, 1, db);

			fread(temp3, 10, 1, db);

			fread(&plane.type, 3, 1, db);

			fread(&plane.descrip, 80, 1, db);

			x = 0;

			for(int a = 0; a < 10; a++) {

				if(temptest[a]!=temp[a]) {
				
					x = 1;

				}

			}

			for(int a = 0; a < 10; a++) {

				temptest[a]=temp[a];

			}

			if(x == 1) {

				printf("\n%s", plane.name);

				printf("\n%s", temp);

				printf("\n%s", temp2);

				printf("\n%s", temp3);

				printf("\n%s", plane.type);

				printf("\n%s\n", plane.descrip);

			}

		}

	// If the user doesn't type "I" (or "i") or "A" (or "a")
	} else {

		printf("You have made a grave mistake. If this was accidental, please run the program again.");

	}

}

//Mr. Pajela's Code
/* * Gets one line of data from input. Returns an empty string on * end of file. If data line will not fit in allotted space, stores * portion that does fit and discards rest of input line. */
char *scan_line_stdin(char *dest, int dest_len) {
	int i, ch;  /* Gets next line one character at a time. */
	i = 0;
	for (ch = getchar(); ch != '\n' && ch != EOF && i < dest_len - 1; ch = getchar()) {
		dest[i++] = ch;
	}
	dest[i] = '\0';  /* Discards any characters that remain on input line */
	while (ch != '\n' && ch != EOF) {
		ch = getchar();
	}
	return(dest);
}


