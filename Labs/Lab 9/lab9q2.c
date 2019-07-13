/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 9 Question 2
	
	This program takes and implements the functions from "lab9q2.h" to deal with bibliography data.
*/

#include <stdio.h>
#include <string.h>
#include "lab9q2.h"

//Allows user to add a source to the bibliography
void addSource(Bibliography *b) {
	
	bibliographyData bd;
	
	char choice;

	printf("\nWhat is the type of your source?\n\n");

	printf("a. Book\n");

	printf("b. Encyclopedia\n");

	printf("c. Newspaper\n");

	printf("d. Periodical\n");

	printf("e. Website\n\n");

	printf("Please enter your choice:\n");

	scanf("%c", &choice);

	if(choice == 'a' || choice == 'A') {

		bd.component = book;

		printf("Please enter the title:\n");

		scanf(" %s", (bd.source.book.title));

		printf("Please enter the author:\n");

		scanf(" %s", (bd.source.book.author));

		printf("Please enter the publisher:\n");

		scanf(" %s", (bd.source.book.publisher));

		printf("Please enter the publication year:\n");

		scanf("%d", &(bd.source.book.yearPub));

	} else if (choice == 'b' || choice == 'B') {

		bd.component = encyclopedia;

		printf("Please enter the title:\n");

		scanf(" %s", (bd.source.encyclopedia.title));

		printf("Please enter the volume:\n");

		scanf("%d", &(bd.source.encyclopedia.volume));

		printf("Please enter the publisher:\n");

		scanf(" %s", (bd.source.encyclopedia.publisher));

		printf("Please enter the page number:\n");

		scanf("%d", &(bd.source.encyclopedia.page));

	}  else if (choice == 'c' || choice == 'C') {

		bd.component = newspaper;

		printf("Please enter the name:\n");

		scanf(" %s", (bd.source.newspaper.name));

		printf("Please enter the article title:\n");

		scanf(" %s", (bd.source.newspaper.articleTitle));

		printf("Please enter the author:\n");

		scanf(" %s", (bd.source.newspaper.author));

		printf("Please enter the day of issue:\n");

		scanf("%d", &(bd.source.newspaper.issueDate.day));

		printf("Please enter the month of issue:\n");

		scanf("%d", &(bd.source.newspaper.issueDate.month));

		printf("Please enter the year of issue:\n");

		scanf("%d", &(bd.source.newspaper.issueDate.year));

	}  else if (choice == 'd' || choice == 'D') {

		bd.component = periodical;

		printf("Please enter the name:\n");

		scanf(" %s", (bd.source.periodical.name));

		printf("Please enter the author:\n");

		scanf(" %s", (bd.source.periodical.author));

		printf("Please enter the year:\n");

		scanf("%d", &(bd.source.periodical.year));

		printf("Please enter the volume:\n");

		scanf("%d", &(bd.source.periodical.volume));

		printf("Please enter the page number:\n");

		scanf("%d", &(bd.source.periodical.page));

	} else if (choice == 'e' || choice == 'E') {

		bd.component = website;

		printf("Please enter the title:\n");

		scanf(" %s", (bd.source.website.title));

		printf("Please enter the URL:\n");

		scanf(" %s", (bd.source.website.url));

	} else {

		printf("\nYou managed to not follow the simple instructions. Please try again if this was a mistake.\n\n");

		return;

	}

	printf("\nPlease enter a description:\n");

	scanf(" %s", (bd.description));

	b->entries[b->size] = bd;

	b->size++;
}

//Allows user to modify the source
void modifyRecord(bibliographyData *b) {

	displaySource(*b);

	char choice;

	printf("What would you like to modify?\n");
	printf("a. Source Type\nb. Description\nEnter your choice:\n");
	scanf("%c", &choice);

	if(choice == 'a' || choice == 'A') {
		char choice2;
		printf("What is the type of your source?\n");
		printf("a. Book\n");
		printf("b. Encyclopedia\n");
		printf("c. Newspaper\n");
		printf("d. Periodical\n");
		printf("e. Website\n\n");
		printf("Enter your choice:\n");
		scanf("%c", &choice2);

		if(choice2 == 'a' || choice2 == 'A') {

			b->component = book;

			printf("Please enter the title:\n");

			scanf(" %s", (b->source.book.title));

			printf("Please enter the author:\n");

			scanf(" %s", (b->source.book.author));

			printf("Please enter the publisher:\n");

			scanf(" %s", (b->source.book.publisher));

			printf("Please enter the publication year:\n");

			scanf("%d", &(b->source.book.yearPub));

		} else if(choice2 == 'b' || choice2 == 'B') {

			b->component = encyclopedia;

			printf("Please enter the title:\n");

			scanf(" %s", (b->source.encyclopedia.title));

			printf("Please enter the volume:\n");

			scanf("%d", &(b->source.encyclopedia.volume));

			printf("Please enter the publisher:\n");

			scanf(" %s", (b->source.encyclopedia.publisher));

			printf("Please enter the page number:\n");

			scanf("%d", &(b->source.encyclopedia.page));

		} else if(choice2 == 'c' || choice2 == 'C') {

			b->component = newspaper;

			printf("Please enter the name:\n");

			scanf(" %s", (b->source.newspaper.name));
 
			printf("Please enter the article title:\n");

			scanf(" %s", (b->source.newspaper.articleTitle));

			printf("Please enter the author:\n");

			scanf(" %s", (b->source.newspaper.author));

			printf("Please enter the day of issue:\n");
			scanf("%d", &(b->source.newspaper.issueDate.day));

			printf("Please enter the month of issue:\n");

			scanf("%d", &(b->source.newspaper.issueDate.month));

			printf("Please enter the year of issue:\n");

			scanf("%d", &(b->source.newspaper.issueDate.year));

		} else if(choice2 == 'd' || choice2 == 'D') {

			b->component = periodical;

			printf("Please enter the name:\n");

			scanf(" %s", (b->source.periodical.name));

			printf("Please enter the author:\n");

			scanf(" %s", (b->source.periodical.author));

			printf("Please enter the year:\n");

			scanf("%d", &(b->source.periodical.year));

			printf("Please enter the volume:\n");

			scanf("%d", &(b->source.periodical.volume));

			printf("Please enter the page number:\n");

			scanf("%d", &(b->source.periodical.page));

		} else if(choice2 == 'e' || choice2 == 'E') {

			b->component = website;

			printf("Please enter the title:\n");

			scanf(" %s", (b->source.website.title));

			printf("Please enter the URL:\n");

			scanf(" %s", (b->source.website.url));

		} else {

			printf("That is not a valid source type");

		}

	} else if(choice == 'b' || choice == 'B') {

		printf("Please enter a new description:\n");

		scanf(" %s", b->description);

	} else {

		printf("\nYou managed to not follow the simple instructions. Please try again if this was a mistake.\n\n");

	}

}

//Allows user to access a source
bibliographyData *accessSource(Bibliography *b) {

	char choice;

	printf("How do you want to access the source?\n");

	printf("\na. Name\nb. Title\nc. Author\nEnter your choice> ");

	scanf("%c", &choice);

	if(choice == 'a' || choice == 'A') {

		char name[MAXNAME];

		printf("Please enter the name:\n");

		scanf(" %s", name);

		for(int a = 0; a < b->size; a++) {

			if(b->entries[a].component == newspaper) {

				if(strcmp(b->entries[a].source.newspaper.name, name) == 0) {

					return(&(b->entries[a]));

				}

			} else if(b->entries[a].component == periodical) {

				if(strcmp(b->entries[a].source.periodical.name, name) == 0) {

					return(&(b->entries[a]));

				}

			}

		}

	} else if (choice == 'b' || choice == 'B') {

		char title[MAXNAME];

		printf("Please enter the title:\n");

		scanf(" %s", title);

		for(int a = 0; a < b->size; a++) {

			if(b->entries[a].component == book) {

				if(strcmp(b->entries[a].source.book.title, title) == 0) {

					return(&(b->entries[a]));

				}

			} else if(b->entries[a].component == encyclopedia) {

				if(strcmp(b->entries[a].source.encyclopedia.title, title) == 0) {

					return(&(b->entries[a]));

				}

			} else if(b->entries[a].component == website) {

				if(strcmp(b->entries[a].source.website.title, title) == 0) {

					return(&(b->entries[a]));

				}

			}

		}

	} else if (choice == 'c' || choice == 'C') {

		char author[MAXNAME];

		printf("Please enter the author:\n");

		scanf(" %s", author);

		for(int a = 0; a < b->size; a++) {

			if(b->entries[a].component == book) {

				if(strcmp(b->entries[a].source.book.author, author) == 0) {

					return(&(b->entries[a]));

				}

			} else if(b->entries[a].component == newspaper) {

				if(strcmp(b->entries[a].source.newspaper.author, author) == 0) {

					return(&(b->entries[a]));

				}

			} else if(b->entries[a].component == periodical) {

				if(strcmp(b->entries[a].source.periodical.author, author) == 0) {

					return(&(b->entries[a]));

				}

			}

		}

	}

	printf("Your choice was invalid");

	return(accessSource(b));

}

//Allows user to state the order of the source
void markSource(bibliographyData *bd) {

	printf("Please enter the serial number of the source:\n");

	scanf("%d", &(bd->entryNum));

}

//Allows user to store the Bibliography in a .txt file
void storeDatabase(Bibliography b, FILE *output) {

	for(int a = 0; a < b.size; a++) {

		if(b.entries[a].component == book) {

			fprintf(output, "book\n");

			fprintf(output, "%s\n", b.entries[a].source.book.title);

			fprintf(output, "%s\n", b.entries[a].source.book.author);

			fprintf(output, "%s\n", b.entries[a].source.book.publisher);

			fprintf(output, "%d\n\n", b.entries[a].source.book.yearPub);

		} else if(b.entries[a].component == encyclopedia) {

			fprintf(output, "encyclopedia\n");

			fprintf(output, "%s\n", b.entries[a].source.encyclopedia.title);

			fprintf(output, "%d\n", b.entries[a].source.encyclopedia.volume);

			fprintf(output, "%s\n", b.entries[a].source.encyclopedia.publisher);

			fprintf(output, "%d\n\n", b.entries[a].source.encyclopedia.page);

		} else if(b.entries[a].component == newspaper) {

			fprintf(output, "newspaper\n");

			fprintf(output, "%s\n", b.entries[a].source.newspaper.name);

			fprintf(output, "%s\n", b.entries[a].source.newspaper.articleTitle);

			fprintf(output, "%s\n", b.entries[a].source.newspaper.author);

			fprintf(output, "%2d %2d %4d\n\n",  				b.entries[a].source.newspaper.issueDate.month, 			b.entries[a].source.newspaper.issueDate.day, 				b.entries[a].source.newspaper.issueDate.year);

		} else if(b.entries[a].component == periodical) {

			fprintf(output, "periodical\n");

			fprintf(output, "%s\n", b.entries[a].source.periodical.name);

			fprintf(output, "%s\n", b.entries[a].source.periodical.author);

			fprintf(output, "%d\n", b.entries[a].source.periodical.year);

			fprintf(output, "%d\n", b.entries[a].source.periodical.volume);

			fprintf(output, "%d\n\n", b.entries[a].source.periodical.page);

		} else if(b.entries[a].component == website) {

			fprintf(output, "website\n");

			fprintf(output, "%s\n", b.entries[a].source.website.title);

			fprintf(output, "%s\n\n", b.entries[a].source.website.url);

		}

	}

}

//ALlows user to load a database from a given .txt file
Bibliography loadDatabase(FILE *input) {

	Bibliography b;

	char line[MAXDESCRIP];

	int EOFdetect = fscanf(input, "%s", line);

	while(EOFdetect != EOF) {

		if(strcmp(line, "book") == 0) {

			b.entries[b.size].component = book;

			fscanf(input, "%s", b.entries[b.size].source.book.title);

			fscanf(input, "%s", b.entries[b.size].source.book.author);

			fscanf(input, "%s", b.entries[b.size].source.book.publisher);

			fscanf(input, "%d", &(b.entries[b.size].source.book.yearPub));

			b.size++;

		} else if(strcmp(line, "encyclopedia") == 0) {

			b.entries[b.size].component = encyclopedia;

			fscanf(input, "%s", b.entries[b.size].source.encyclopedia.title);

			fscanf(input, "%d", &(b.entries[b.size].source.encyclopedia.volume));

			fscanf(input, "%s", b.entries[b.size].source.encyclopedia.publisher);

			fscanf(input, "%d", &(b.entries[b.size].source.encyclopedia.page));

			b.size++;

		} else if(strcmp(line, "newspaper") == 0) {

			b.entries[b.size].component = newspaper;

			fscanf(input, "%s", b.entries[b.size].source.newspaper.name);

			fscanf(input, "%s", b.entries[b.size].source.newspaper.articleTitle);

			fscanf(input, "%s", b.entries[b.size].source.newspaper.author);

			fscanf(input, "%d%d%d", 				&(b.entries[b.size].source.newspaper.issueDate.month), &(b.entries[b.size].source.newspaper.issueDate.day), &(b.entries[b.size].source.newspaper.issueDate.year));

			b.size++;

		} else if(strcmp(line, "periodical") == 0) {

			b.entries[b.size].component = periodical;

			fscanf(input, "%s", b.entries[b.size].source.periodical.name);

			fscanf(input, "%s", b.entries[b.size].source.periodical.author);

			fscanf(input, "%d", &(b.entries[b.size].source.periodical.year));

			fscanf(input, "%d", &(b.entries[b.size].source.periodical.volume));

			fscanf(input, "%d", &(b.entries[b.size].source.periodical.page));

			b.size++;

		} else if(strcmp(line, "website") == 0) {

			b.entries[b.size].component = website;

			fscanf(input, "%s", b.entries[b.size].source.website.title);

			fscanf(input, "%s", b.entries[b.size].source.website.url);

			b.size++;

		}

		EOFdetect = fscanf(input, "%s", line);

	}

	return(b);

}

//Displays unused sources, used sources in order of selection and all sources in order by title/name
void displaySources(Bibliography b) {

	printf("Unused sources:\n");

	for(int a = 0; a < b.size; a++) {

		if(b.entries[a].entryNum == 0) {

			displaySource(b.entries[a]);

			printf("\n");

		}

	}

	printf("Used sources:\n");

	for(int a = 1; a < b.size; a++) {

		for(int x = 0; x < b.size; x++) {

			if(b.entries[x].entryNum == a) {

				displaySource(b.entries[a]);

				printf("\n");

			}

		}

	}

	printf("All Sources:\n"); //Not ordered

	for(int a = 0; a < b.size; a++) {

		displaySource(b.entries[a]);

		printf("\n");

	}

}

//Displays data about a source
void displaySource(bibliographyData b) {
	if(b.component == book) {

		printf("Title: %s\n", b.source.book.title);

		printf("Author: %s\n", b.source.book.author);

		printf("Publisher: %s\n", b.source.book.publisher);

		printf("Publication Year: %d\n", b.source.book.yearPub);

	} else if(b.component == encyclopedia) {

		printf("Title: %s\n", b.source.encyclopedia.title);

		printf("Volume: %d\n", b.source.encyclopedia.volume);

		printf("Publisher: %s\n", b.source.encyclopedia.publisher);

		printf("Page: %d\n", b.source.encyclopedia.page);

	} else if(b.component == newspaper) {

		printf("Name: %s\n", b.source.newspaper.name);

		printf("Article Title: %s\n", b.source.newspaper.articleTitle);

		printf("Author: %s\n", b.source.newspaper.author);

		printf("Issue Date: %2d/%2d/%4d\n", b.source.newspaper.issueDate.month, b.source.newspaper.issueDate.day, b.source.newspaper.issueDate.year);

	} else if(b.component == periodical) {

		printf("Name: %s\n", b.source.periodical.name);

		printf("Author: %s\n", b.source.periodical.author);

		printf("Year: %d\n", b.source.periodical.year);

		printf("Volume: %d\n", b.source.periodical.volume);

		printf("Page: %d\n", b.source.periodical.page);

	} else if(b.component == website) {

		printf("Title: %s\n", b.source.website.title);

		printf("URL: %s\n", b.source.website.url);

	}

}
