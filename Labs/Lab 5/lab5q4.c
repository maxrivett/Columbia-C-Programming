/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 5 Question 4
	
	This program takes an inputted noun from the user, and outputs the plural form of the respective noun.

Side note: The code looks good to me after looking over it many times but I keep getting an error that I don't understand when I try to compile it. The error reads: "warning: function returns address of local variable [-Wreturn-local-addr]
  return b;"


*/

#include <stdio.h>
#include <string.h>

char *substr(char *str, int firstLetter, int len);

int main(void) {

	int len = 0;

	//Gets input from user
	printf("How many letters long is your noun:\n");

	scanf("%d", &len);

	char str[len];

	printf("Please enter your noun:\n");

	scanf("%s", str);

	char *sub = substr(str, len - 2, 2);

	char strnew[len+2];

	if(sub[1] == 'y') {

		char *tmp = substr(str, 0, len-1);

		printf("The plural of your word, \"%s\", is \"%sies\".\n", str, tmp);

	} else if(sub[1] == 's' || (sub[0] == 's' && sub[1] == 'h') || (sub[0] == 'c' && sub[1] == 'h')) {

		//fgets(strnew, "%s", str);
		sprintf(strnew, "%s", str);

		printf("The plural of your word, \"%s\", is \"%ses\".\n", str, strnew);

	} else {

		//fgets(strnew, "%s", str);
		sprintf(strnew, "%s", str);

		printf("The plural of your word, \"%s\", is \"%ss\".\n", str, strnew);

	}

	return(0);
}

// Returns a substring of str that begins with firstLetter and is len characters long
char *substr(char *str, int firstLetter, int len) {

	char b[len+1];

	for(int a = 0; a < len; a++) {

		b[a] = str[firstLetter + b];

	}

	b[len] = '\0';

	return b;
}
