// generate characters for a starship RPG
// Author: Thomas Waggoner

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define REROLLS_ALLOWED 3
#define CREW_SIZE 5
#define CAP 0
#define COM 1
#define ENG 2
#define NAV 3
#define SEC 4

#define TERRAN 1
#define MARTIAN 2
#define VENUSIAN 3
#define SATURIAN 4

#define SIX_SIDED 6
#define TEN_SIDED 10

// Function Prototypes
void generate_crew(void);
void generate_crew_member(int crew_id);
void generate_race(int crew_id, int testing);
void generate_skills(int crew_id);
void print_crew_report(void);
void print_skill(int lvl);
int roll_dice(int rolls, int dice_sides);
int gen_enc_skill(int attr1, int attr2,int bonus_roll);
int decode_skill_value(int skill_cd);
int skill_bonus_lvl(int skill_cd);

/*
    List of character attributes:
        Charisma
        Intelligence
        Psionics
        Strength
        Agility
*/
int chCharisma[CREW_SIZE] = {0};
int chIntel[CREW_SIZE] = {0};
int chPsi[CREW_SIZE] = {0};
int chStr[CREW_SIZE] = {0};
int chAgl[CREW_SIZE] = {0};
// the rest of attributes represented in the same way

char chRace[CREW_SIZE] = {'Z','Z','Z','Z','Z'};

/*
    List of character skills
        SKILL       DEPENDS ON
        -----       ----------
        Nav         Inteligence, Psionics
        Eng         Intelligence, Agility
        Tac         Strength, Agility
        Lead        Charisma, Intelligence
        Dip         Charisma, Psionics

*/
int chNav[CREW_SIZE] = {0};
int chEng[CREW_SIZE] = {0};
int chTac[CREW_SIZE] = {0};
int chLead[CREW_SIZE] = {0};
int chDip[CREW_SIZE] = {0};
// the rest of the skills done in in similar arrays, but encode natural
// rolls into the skill value; decode when needing to display or use

/* 
Psuedocode for Character Gen program

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
    // test run conditions

func generate_crew()
    for each crew position
        generate_char()

func generate_char(crew_id)
    generate_char_attributes()
    generate_char_race()
    generate_char_skills()

func generate_random(max_value);

func roll_dice(number of dice, number of die sides)

func encode_char_skill()

int func decode_char_skill()

func print_crew_report()
    print report header
    for each crew member
        print crew abilities and skills and race
*/
int main(void) {
    // initialize services
    time_t t;
    srand(time(&t));

    // prompt user for test run [0 is no testing] T 1 indicates testcase 1
    puts("Enter test case number 0-9 (0 or newline means normal run):");
    char t_response;
    scanf(" %c", &t_response);
    switch (t_response) {
        case '\n':
        case '0':
            // normal run
            generate_crew();
            break;
        case '1': 
            // sets crew member attributes to ensure all skill values are tested. Includes
            // racial modifiers to abilities by testing all races as well.
            /* input:
                1
                Q
            
               output (no leading spaces in actual output):
                Enter test case number 0-9 (0 or newline means normal run):
                       Race   Attributes         Skills
                Crew          C  I  S  P  A      N    E    L    T    D
                Cap    T      3  3  3  3  3     -4+  -4+  -4+  -4+  -4+
                Com    M      6  6  4  8  7     -1*  -2*  -2*  -2*  -1*
                Eng    V     13 11 13 13 11      0    0    0    0    0
                Nav    S     15 18 15 17 16      2*   2*   2*   2*   2*
                Sec    T     18 18 18 18 18      4+   4+   4+   4+   4+
                Enter C to reroll the crew or a crew number [0-4] to reroll reroll a crew member. You have 3 of 3 rerolls left:
                Enjoy the game!
           */
            {
                int attr_val;
                int test_bonuses[CREW_SIZE] = {1, 2, 20, 80, 99};
                int test_attrs[CREW_SIZE] = {3, 6, 12, 16, 18};
                
                // generate test values for a crew 
                for (int i = 0; i < 5; ++i) {
                    chCharisma[i] = test_attrs[i];
                    chIntel[i] = test_attrs[i];
                    chPsi[i] = test_attrs[i];
                    generate_race(i, (i % 4) + 1);
                    chLead[i] = gen_enc_skill(chCharisma[i], chIntel[i], test_bonuses[i]);
                    chNav[i] = gen_enc_skill(chIntel[i], chPsi[i], test_bonuses[i]);
                }
            }
            break;
        case '2':
            // TODO: Implement your Test Case 2 here
            //
            // write test setup to test changing a single character consistently 
            // you can modify functions but minimize code only evaluated during a test.
            // provide the required input and expected output
        
        case '3':
            // TODO: Implement your Test Case 3 here
            //
            // write test setup to test changing entire crew consistently
            // you can modify functions but minimize code only evaluated during a test.
            // provide the required input and expected output


        default:
            break;
    }
    
    print_crew_report();

    // start prompting user for changes to rolled crew
    for (int i = REROLLS_ALLOWED; i > 0; i--) {
        char rr;
        int flag = 1;
        printf("Enter C to reroll the crew or a crew number [0-4] to reroll "
                   "reroll a crew member. You have %d of 3 rerolls left:\n", i);
        do {
            rr = getchar();
            if (rr == 'C' || rr == 'Q'|| (rr >= '0' && rr < '5'))
                flag = 0; // exit loop
            else if (rr == '\n' || rr == ' ')
                continue;
            else
                printf("Invalid option: %c", rr);

        } while (flag);

        if (rr == 'C')
            generate_crew();
        else if (rr == 'Q') {
            puts("Enjoy the game!");
            exit(1);
        } else 
            generate_crew_member(rr - '0');
        
        print_crew_report();
    }

    puts("You have exhaused your re-roll options. This is your crew. Enjoy the game!");


} // end main

/*
    print_crew_report:

    TODO: Implement displaying unimplmented attributes and skills.

    Prints table displaying crew position, race, attribute values, and skill values.
    Skill values denote if the crew member is a natural or extra-natural skill.
*/
void print_crew_report(void) {
    puts("       Race   Attributes         Skills");
    puts("Crew          C  I  S  P  A      N    E    L    T    D");
    for (int id = 0; id < CREW_SIZE; ++id) {
        switch (id) {
            case 0:
                printf("Cap    ");
                break;
            case 1:
                printf("Com    ");
                break;
            case 2: 
                printf("Eng    ");
                break;
            case 3:
                printf("Nav    ");
                break;
            case 4:
                printf("Sec    ");
                break;
        } // end switch

        printf("%c     ", chRace[id]);
        printf("%2d ", chCharisma[id]);
        printf("%2d ", chIntel[id]);
        printf(" 0 %2d  0    ", chPsi[id]);
        print_skill(chNav[id]);
        printf("   0  ");
        print_skill(chLead[id]);
        printf("   0    0\n");
    }

}

/*
    print_skill:

    Helper function that prints the skill value correctly by decoding the skill code
    and flaging the natural roll with a * or +. 
*/
void print_skill(int skill_cd) {
    int bonus = skill_bonus_lvl(skill_cd);
    int skill_val = decode_skill_value(skill_cd);

    printf(" ");  // print padding to the left
    if (bonus) {
        char bonus_char = bonus == 1 ? '*' : '+';
        if (skill_val > 0)
            printf(" ");
        printf("%d%c", skill_val, bonus_char);
    } else 
        printf(" %d ", skill_val );
}


void generate_crew(void) {
    for (int i = 0; i < CREW_SIZE; ++i) 
        generate_crew_member(i);
}

/*
   generate_crew_member: 

   TODO: Finish attribute generation
  
   Uses the crew_id to generate crew member stats. The stats
   are maintained in global arrays. 
*/
void generate_crew_member(int crew_id) {
    // generate basic attributes
    chCharisma[crew_id] = roll_dice(3, SIX_SIDED);
    chIntel[crew_id] = roll_dice(3, SIX_SIDED);
    chPsi[crew_id] = roll_dice(3, SIX_SIDED);
    // need to finish basic attributes

    
    generate_race(crew_id, 0);

    generate_skills(crew_id);
} 

/*
 * roll_dice:
    Takes the number of dice rolls and dice sides.
    
    Returns the sum of the all the dice rolls. 
*/
int roll_dice(int rolls, int dice_sides) {
    int sum = 0;
    for (int i = 0; i < rolls; ++i) {
        sum += (rand() % dice_sides) + 1;
    }
    
    return sum;
}

/*
    generate_race:

    TODO: Finish implementing racial attribute adjustment

    Generates a random race and then adjusts attributes accordingly. 
    Operates on global arrays.
*/
void generate_race(int crew_id, int testing) {
    int race;
    if (!testing)
        race = rand() % 4 + 1;
    else 
        race = testing;
    
    switch (race) {
        case TERRAN:
            chRace[crew_id] = 'T';

            break;
        case MARTIAN:
            chRace[crew_id] = 'M';
            chPsi[crew_id] += 2;
            // strength and agility adjustments not implemented
            break;
        case VENUSIAN:
            chRace[crew_id] = 'V';
            // implement racial bonues
            break;
        case SATURIAN:
            chRace[crew_id] = 'S';
            // implement racial bonues
            break;
        default:
            puts("Something went terribly wrong to wind up here.");
            exit(1);
            break;

    }
} // end generate_race

/*
    generate_skills:

    TODO: Finish generating all skills

    Skills are based on critical attribute values and modified by
    natural bonus, we store the natural bonus in the skill array. 
    
*/
#define ROLL_NEW -1
void generate_skills(int crew_id) {
    chLead[crew_id] = gen_enc_skill(chCharisma[crew_id], chIntel[crew_id], ROLL_NEW);
    chNav[crew_id] = gen_enc_skill(chIntel[crew_id], chPsi[crew_id], ROLL_NEW);
    // remaining skills needed

}

/*
    encode_skill

    Codes the average critical skills according to the table:
    AVG_ATTR    Skill_cd
    --------    --------
      3           1
      4-6         2
      7-14        0
      15-17       3
      18          4

    Natural bonus is rolled and encoded as
    NAT_BONUS   Bonus_cd
    ---------   --------
      0-1         10
      2-19        20
      20-79       0
      80-97       30
      98-99       40

    Encoded skill is skill_cd + bonus_cd
*/
int gen_enc_skill(int attr1, int attr2, int bonus_roll) {
    int skill_cd;
    int avg_attr = (attr1 + attr2) / 2;
    if (avg_attr == 3) 
        skill_cd = 2;
    else if (avg_attr < 7)
        skill_cd = 1;
    else if (avg_attr < 15)
        skill_cd = 0;
    else if (avg_attr < 18)
        skill_cd = 3;
    else
        skill_cd = 4;
    
    
    if (bonus_roll < 0)
        bonus_roll = roll_dice(1, TEN_SIDED) * 10 + roll_dice(1, TEN_SIDED);
    int bonus_cd;
    if (bonus_roll < 2)
        bonus_cd = 20;
    else if (bonus_roll < 20)
        bonus_cd = 10;
    else if (bonus_roll < 80)
        bonus_cd = 0;
    else if (bonus_roll < 98)
        bonus_cd = 30;
    else
        bonus_cd = 40;
    
    return bonus_cd + skill_cd;

} // end gen_enc_skill

/*
    decode_skill_value:

    decodes the skill and returns the skill value.

    ability_based skill_cd = encoded_skill_cd % 10
    nat_roll_skill_cd = encoded_skill_cd / 10

    ability cd table (nat_roll_skill_cd's are the same except x10)
    ability_skill_cd    Value
    ----------------    -----
    0                   0
    1                   -2
    2                   -1
    3                   1
    4                   2
*/
int decode_skill_value(int encoded_skill) {
    int skill_value = 0;
    int skill_cd = encoded_skill % 10;
    int bonus_cd = encoded_skill / 10;

    // defensive coding
    if (skill_cd > 4 || bonus_cd > 4) {
        puts("Something is very wrong with an encoded skill value.");
        exit(1);
    }

    if (skill_cd > 0)
        if (skill_cd < 3)
            skill_value = skill_cd * -1;
        else 
            skill_value = skill_cd - 2;
     
    if (bonus_cd > 0)
        if (bonus_cd < 3)
            skill_value += (bonus_cd * -1);
        else
            skill_value += (bonus_cd - 2);
    
    return skill_value;
} // end decode_skill_value

/*
    skill_bonus_lvl:

    Returns 0, 1, or 2 for the bonus level of the skill.
*/
int skill_bonus_lvl(int skill_cd) {
    int decode_bonus = skill_cd / 10;

    if (decode_bonus > 2)
        return decode_bonus - 2;
    else
        return decode_bonus;
}
