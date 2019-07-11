/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 5 Question 3
	
	This program determines whether or not a chemical is a hydroxide or not, and outputs the answer.
*/

#include <stdio.h>
#include <string.h>

void substr(char *str, int firstNum, int length, char subst[]);

int hydroxide(char *str);

int main() {

	//char chem[10];
	
	//Runs the hydroxide function using the chemicals given
	if(hydroxide("KOH")) {

		printf("KOH is a hydroxide.\n");

	} else {

		printf("KOH is not a hydroxide.\n");

	}

	if(hydroxide("H2O2")) {

		printf("H2O2 is a hydroxide.\n");

	} else {

		printf("H2O2 is not a hydroxide.\n");

	}

	if(hydroxide("NaCl")) {

		printf("NaCl is a hydroxide.\n");

	} else {

	printf("NaCl is not a hydroxide.\n");

	}

	if(hydroxide("NaOH")) {

		printf("NaOH is a hydroxide.\n");

	} else {

		printf("NaOH is not a hydroxide.\n");

	}

	if(hydroxide("C9H8O4")) {

		printf("C9H8O4 is a hydroxide.\n");

	} else {

		printf("C9H8O4 is not a hydroxide.\n");

	}

	if(hydroxide("MgOH")) {

		printf("MgOH is a hydroxide.\n");

	} else {

		printf("MgOH is not a hydroxide.\n");

	}
/*	Tried to do something here; didn't really work out.

	printf("\nNow you try! Input a chemical composition and the program will output whether it is a hydroxide or not:\n");
	scanf("%s", chem[10]);
	
	if(hydroxide(chem)) {

		printf("%s is a hydroxide.\n", chem);

	} else {

		printf("%s is not a hydroxide.\n", chem);

	}
*/
	return(0);
}

// Returns 1 if last two characters are "OH", returns 0 otherwise
int hydroxide(char *str) {

	int a = 0;

	while(str[a] != '\0') {

		a++;

	}

	char subst[2];

	substr(str, a - 2, 2, subst);

	if(strcmp(subst, "OH") == 0) {

		return(1);

	} else {

		return(0);

	}
}


// str is a string that has at least firstNum + length chars, the substring of str is stored in subst
void substr(char *str, int firstNum, int length, char subst[]) {

	char x[length+1];

	for(int a = 0; a < length; a++) {

		subst[a] = str[firstNum + a];

	}

	subst[length] = '\0';
}

