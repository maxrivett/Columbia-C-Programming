/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 9 Question 2
	
	This header file defines a structure used to store data for a bibliography as well as declaring functions that are used to add or modify data entries.

*/

#define MAXNAME 50
#define MAXDESCRIP 200
#define MAXENTRIES 50

typedef enum {
	book,
	encyclopedia,
	newspaper,
	periodical,
	website
} sourceCategory;

typedef struct {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	char title[MAXNAME];
	char author[MAXNAME];
	char publisher[MAXNAME];
	int yearPub;
} Book;

typedef struct {
	char title[MAXNAME];
	int volume;
	char publisher[MAXNAME];
	int page;
} Encyclopedia;

typedef struct {
	char name[MAXNAME];
	char articleTitle[MAXNAME];
	char author[MAXNAME];
	Date issueDate;
} Newspaper;

typedef struct {
	char name[MAXNAME];
	char author[MAXNAME];
	int year;
	int volume;
	int page;
} Periodical;

typedef struct {
	char title[MAXNAME];
	char url[MAXNAME];
} Website;

typedef union {
	Book book;
	Encyclopedia encyclopedia;
	Newspaper newspaper;
	Periodical periodical;
	Website website;
} Source;

typedef struct {
	Source source;
	sourceCategory component;
	char description[MAXDESCRIP];
	int entryNum;
} bibliographyData;

typedef struct {
	bibliographyData entries[MAXENTRIES];
	int size;
} Bibliography;

// Allows the user to input a source to the bibliography
extern void inputSource(Bibliography *b);

// Allows the user to modify the source
extern void modifySource(bibliographyData *b);

// Allows the user to access a source
extern bibliographyData *accessSource(Bibliography *b);

// Allows the user to mark the source as to the order in which it will be used
extern void markSource(bibliographyData *bd);

// Allows user to store the bibliography in a .txt file
extern void storeBiblio(Bibliography b, FILE *output);

// ALlows user to load a database from a given .txt file
extern Bibliography loadDatabase(FILE *input);

// Displays unused sources/used sources in order of selection and all sources in order by title
extern void displaySources(Bibliography b);

// Prints source to stdout
extern void displaySource(bibliographyData b);

