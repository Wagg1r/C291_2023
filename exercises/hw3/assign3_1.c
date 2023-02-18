#include <stdio.h>

int main(){
//a

unsigned int numA = 1001;
printf("%-12.6u \n",numA);

//b 
// this makes an array of size 10 and then the while loop fills up the positions as long as
// you don't enter z and its under 10
char arrayB[10];
int i = 0;
char letter = 'a';
while (letter != 'z' && i < 10) {
	if (letter != 'z'){
		printf("input up to 10 times a letter into the array: \n");
		scanf(" %c", &letter );
		arrayB[i] = letter;
		}
	i++;
	}

//c
float numC = 7.350;
printf("%8.3f \n",numC);



//d
int octal;
printf("enter an octal value: ");
scanf("%o", &octal);


//e adds the + sign to 300
printf("%d \n",300);
printf("%+d \n",300);

//f it is an unsigned meaning it can never be negative so it gives back a different value
unsigned int numF = -300;
printf("%u \n",numF);

//g it takes the decimal integer 100 and converts that number into an octet
int numG= 100;
printf("0%o \n",numG);

//h
int hex;
printf("enter a hexidecimal: ");
scanf("%x", &hex);

//i
int numI = 100;
printf("\n 0x%x \n",numI);

//j takes in three differnt integers for time
int hour, minute, second;
printf("Enter time hour-minute-second: ");
scanf("%d%*c%d%*c%d", &hour, &minute, &second);

printf("\n");
//k takes in three different input integers for time in a specific format

printf("Enter time in the format hour:minute:second: ");
scanf("%d:%d:%d", &hour, &minute, &second);

printf("\n")

//l
char s[50];
printf("Enter a string in the format \"characters\": ");
scanf(" \"%49[^\"]\"", s);

//part 2

//a)it will print the decimal value 32100  
printf( "%-10d\n", 32100 ); 
//b) this should give an error because c is made for only one character.
//I was wrong it did not give an error it simply did not print anything
 printf( "%c\n", "This is a C string" ); 
//c)# will make o print before the number and 
//e will make it print in scientific notation format
//the first input will be put in octet format
//the second will be in hexidecimal and the last in scientific notation
 printf( "%#o\n%#X\n%#e\n", 17, 17, 1008.80609 );  
//d) they are both long intergers the first will print with a space  and the second will print with an + in front
 printf( "% ld\n%+ld\n", 1000000, 8000000 ); 
//e) it will print 10 digites and it will go three places past the decimal
 printf( "%10.3g\n", 265.93738 ); 
//f) a wiled card will take in any thing that has a . in the middle
//the 8 tells it how many digits it holds total and 3 is how many digits past the decimal to display
 printf( "%*.*lf\n", 8, 3, 8125.921654 ); 
//g) E prints in scientific notation. 10 is how many digits to hold and 3 is how many places after the decimal.
 printf( "%10.3E\n", 953.92738 ); 
//h) this is meant to print integers so any decimals will be gotten rid of leaving only the
//whole number
 printf( "%d\n", 20.987 );  


/*
RESUTLTS
   32100

021
0X11
1.008806e+03
 1000000
+8000000
       266
8125.922
 9.539E+02
-1102298464


*/   
return 0;

}
