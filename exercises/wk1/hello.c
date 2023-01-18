/* 
 * Basic C program to print out hello world! 
 * Author: Thomas Waggoner
*/

#include <stdio.h>
#include <unistd.h>

int main(void) {
  int myNumber = 100;
  int counter = 5;
  printf("\" *****{Welcome to C291 Spring 2023 @ IU}, %%%%%% Golden Rule: Start working on everything as early as possible Thanks %%%%%% *****\" \n");
  while (myNumber >= 0){  
  printf("%04d", myNumber);
  fflush(stdout);
  while(counter >= 0) {
	if (myNumber % 2 == 0)
	printf(".");
	sleep(1);
	fflush(stdout);
	counter = counter -1;
	} //ends counter while loop
    counter = 5;
    myNumber = myNumber -1;
    printf("\n");
  } // ends  while loop 
  return(0); 
 } // ends main
