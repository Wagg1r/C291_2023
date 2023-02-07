// generate characters for a starship RPG
// Author: Kurt Seiffert

#include <stdio.h>

#define CREW_SIZE
int main(void) {
    char chCrewPos[CREW_SIZE] = {'Z'};
    // C = Captain; E = Engineering, N = Navigation, R = Communication, ..

    int chCharisma[CREW_SIZE] = {0};
    int chIntel[CREW_SIZE] = {0};
    // the rest of attributes represented in the same way

    char chRace[CREW_SIZE] = {'Z'};

    int chNav[CREW_SIZE] = {0};
    // the rest of the skills done in in similar arrays, but encode natural
    // rolls into the skill value; decode when needing to display or use


/*
    Nav = -1; Natural_skill_roll = 99
    EncodedNav = -101
    if (EncodedNav / 100) 
        EncodedNav % 100 + 2

*/

/* psuedocode for process flow
prompt user for test run
if test_run == 0:
    generate_crew()
    for up to three times
        print_crew_report()
        prompt user - gen new crew, new char, or Quit
        if new_char_request:
            generate_char()
        else if generate_new_crew:
            generate_crew()
        else:
            Quit program
else:
    //do test run indicated by user

func generate_crew()
    for each crew position
        generate_char()

func generate_char()
    generate_char_race()
    generate_char_attributes()
    generate_char_skills()

func generate_random(max_value);

func encode_char_skill()

int func decode_char_skill()

func print_crew_report()
*/

} // end main