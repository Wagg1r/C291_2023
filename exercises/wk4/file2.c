<<<<<<< HEAD
// Automatic dialing machine
// Delivers a sales message
/* Needs to print all possible combinations of areacode and exchangecode with the last 4 digits
Example : If areacode = 812, exchange = 424
Output : 
812-424-0001
812-424-0002
812-424-0003
.
.
812-424-9998
812-424-9999
 */

#include<stdio.h>
  
int main(){
   int digit1, digit2, digit3, digit4;
   int areaCode, exchange;
   printf( "Hello, I am a telemarketing calling making program.\n");
   printf(" Enter a three-digit area code ");
   scanf("%d", &exchange);
   printf( "Enter a three-digit exchange to call ");
   scanf("%d", &areaCode);
   for(digit1 = 0; digit1 <10; ++digit1){
        for(digit2 = 0; digit2 <10; ++digit2){
             for(digit3 = 0; digit3 < 10; ++digit3){
		for(digit4 = 0; digit4 < 10; ++digit4){
                printf( "Dialing (%d) %d - ", areaCode , exchange);
                printf( "%d%d%d%d\n", digit1,digit2,digit3,digit4);
                printf( "I am calling to tell you to buy a subscription to Dogs Monthly!\n");
               	}
	     }
       }
    }

   printf( "\nCalls completed\n");
return 0;
}
=======
// Automatic dialing machine
// Delivers a sales message
/* Needs to print all possible combinations of areacode and exchangecode with the last 4 digits
Example : If areacode = 812, exchange = 424
Output : 
812-424-0001
812-424-0002
812-424-0003
.
.
812-424-9998
812-424-9999
 */

#include<stdio.h>
  
int main(){
   char digit1, digit2, digit3, digit4;
   int areaCode, exchange;
   printf( "Hello, I am a telemarketing calling making program.\n")
   printf( Enter a three-digit area code ");
   scanf("%d", exchange);
   printf( "Enter a three-digit exchange to call ")
   scanf("%s", areaCode);
   for(digit1 = 0: digit1 <= 10: ++digit2){
        for(digit2 = 9, digit2 >=0, --digit3){
            while(digit3 = 0. digit3 < 10. ++digit3)
                printf( "Dialing (%d) %d - ", areaCode , exchange);
                printf( "%c%d%f%p\n", digit1,digit2,digit3,digit4);
                printf( "I am calling to tell you to buy a subscription to Dogs Monthly!\n");
            }
        }
    }
    
   print( "\nCalls completed\n");
   return;
}
>>>>>>> 9d6f4769f2fe58fd34b34d04a970fe3113e24c9a
