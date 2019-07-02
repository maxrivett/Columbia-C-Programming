/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 2 Question 2a
	
	This program asks the user to input a width and a height, and creates a rectangle made out of asterisks that matches the numbers inputted.

*/


#include <stdio.h>
#include <math.h>

int main() {

	int x,
	j,
	a,
	w, //width of the polygon
	h; //height of the polygon
	/*len, //length of the lines in the X
	side, //length of the hypotenuse and long side of the triangle
	r; //radius of the circle */


	// ask the user to input two numbers for width and height
	printf("Enter a value for the width of the rectangle: \n");
	scanf("%d", &w);

	printf("Enter a value for the height of the rectangle: \n");
	scanf("%d", &h);

	if (w < 1 || h < 1) {
		printf("Invalid inputs.\n");
	} else {

		for (x = 0; x < w; x++) {

			printf("*");

		}
		
		
			printf("\n");	
		
			int h2 = h - 2;
			int w2 = w - 2;

	
		for (j = 0; j < h2; j++) {
			
			printf("*");
			for (a = 1; a <= w2; a++) {
				printf(" ");
			}
			printf("*\n");
		}
		
		for (j = 0; j < w; j++) {

			printf("*");

		}
		printf("\n");

	}



/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 2 Question 2b
	
	This program asks the user to input a length that is then used as the two lines in an X.

*/

	int len,
	i,
	b;

	printf("Enter the length for each line in the X\n");
	scanf("%d", &len);
	
	

	for (i = 1; i <= len; i++) {
		for (b = 1; b <= len; b++) {

			if (i == b || b == len - i + 1) {
				printf("*");
			} else {
				printf(" ");
			}

		}
		printf("\n");
	}

/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 2 Question 2a
	
	This program asks the user to input a sidelength for a triangle and then creates a right triangle based off of the number inputted where the right angle is in the bottom-left corner.

*/
		
	int sidelen,
	row,
	column; 																																																													
	printf("Enter the length for the side length of the triangle:\n");
	scanf("%d", &sidelen);

	for (row = 1; row <= sidelen; row++) {
		for (column = 1; column <= row; column++) {
			printf("*");
		}
		printf("\n");
	}

	

/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 2 Question 2d
	
	This program asks the user to input a sidelength for a triangle and then creates a right triangle based off of the number inputted where the right angle is in the top-right corner.

*/
	
	int sidelen1,
	c,
	c1,
	c2;
	


	printf("Enter the length for the side length of the triangle:\n");
	scanf("%d", &sidelen1);



	for (c = 1; c < sidelen1 + 1; c++) {

		for (c1 = 1; c1 < c; c1++) {

			printf(" ");

		}

		for (c2 = sidelen1 + 1; c2 > c1; c2--) {

			printf("*");

		}

		printf("\n");

	}
		
/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 2 Question 2e
	
	This program asks the user to input a width and height and creates a trapezoid accordingly.

*/

	int b2,
	h2,
	l,
	m;



	printf("What would you like the base of the trapezoid to be?:\n");
	scanf("%d", &b2);

	printf("What would you like the height of the trapezoid to be?:\n");
	scanf("%d", &h2);

	int o = b2 - h2;
	


	for (l = 1; l <= h2; l++) {
		for (m = o; m <= b2; m++) {
			printf("*");
		}
		o--;
		printf("\n");
	}


/*
	Author: Max Rivett
	Course: Introduction to Programming in C
	Instructor: Gilbert Pajela
	Assignment: Lab 2 Question 2f
	
	This program prompts the user to input a radius for a circle that is then created out of asterisks.

*/
	
	#define PI 3.1415926535;	
	
	int rad,
	rad2,
	x1,
	x2,
	y1,
	y2,
	dia,
	u,
	u1,
	u2,
	area,
	numasts;

	
	printf("What would you like the radius of the circle to be?:\n");
	scanf("%d", &rad);

	x2 = x1 * x1;
	//y2 = y1 * y1;
	dia = rad * 2;
	rad2 > x2 + y2;
	//area = PI * rad2;
	numasts = 1;

	/*for (u = 1; u <= 2 * rad - 1; u++) {
		printf("*");
	}
	printf("\n");*/

	for(int a5 = -rad; a5 <= rad; a5++) {

		for(int b5 = -rad; b5 <= rad; b5++) {

			if((a5 * a5) + (b5 * b5) < (rad * rad)) {

				printf("*");

			} else {

				printf(" ");

			}

		}

		printf("\n");

	}

	return 0;

}
