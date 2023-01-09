/* 
 * Basic C program to print out hello world! 
 * Author: Kurt Seiffert
*/

#include <stdio.h>

int main(void) {
  int myNumber = 0;
  printf("Hello: Welcome to C291!\n");
  printf("Please enter a number and press ENTER: ");
  scanf("%d", &myNumber);  
  printf("Here is the number yor entered: %d\n",myNumber);
  return(0); 
}


