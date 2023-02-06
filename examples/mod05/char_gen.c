// Program to generate crew for starship RPG game
// Author: Kurt Seiffert

#include <stdio.h>
#define  CREW_SIZE 5
/* psuedo-code for program 

prompt user for test case (T 0 == normal run)
if test case 0 then:
    generate_crew()
    for up to three times
        print_crew_report()
        prompt user to re-roll crew or re-roll character
        if user re-rolls character
            generate_new_character()
        else if new_crew :
            generate_crew()
        else: 
            quit

else:
    // do test case
    

*/


int main(void) {

    int crewID = {0,1,2,3,4};
    char chCrewPos[CREW_SIZE] = {'Z'};
    int chCharisma[CREW_SIZE] = {0};
    // define additional arrays for remaining attributes

    // define the skills reprsentation
    int chNav[CREW_SIZE] = {0};
    // define addtional arrays for remaining skills
    // encode and decode natural skill bonus into the the skill value
    // 100 + for extra natrual, 10+ for normal natural, and negative for naturally bad


    char chRace[CREW_SIZE] = {'Z'};




} // end main