// file: bracetopia.c
// bracetopia is a program that implements a simulator on where agents sit
// in an office and calculates their happiness based on the people sitting
// next to them and whether those other people have the same bracket 
// preferences
// @author Ming Creekmore mec5765
// // // // // // // // // // // // // // // // // // // // // // // // //


#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdbool.h>

/// struct game_state   holds values that define the game
/// size                dimensions of the board
/// strength            strength of preference to be near like people
/// vacancy             percent of vacant spots open
/// percent_end         percent of people that prefer endline
/// delay               the speed at which the simulation updates
/// infinite            whether the game is in infinite mode
struct sim_state {
    int size;
    int strength;
    int vacancy;
    int end;
    int delay;
    bool infinite;
};

/// main: starts the simulation
///
/// @param argc     the number of arguments
/// @argv[]         list of the arguments
///
/// @return int     exit status
int main(int argc, char* argv[]) {
    int opt;
    //default game_state values
    struct sim_state sim = {7, 30, 30, 75, 5000, 1};
    int numcycles;
    sim.infinite = 1;

    while((opt = getopt(argc, argv, "ht:c:d:s:v:e:")) != -1) {
        switch(opt){
        case 'h': //help command
            break;
        case 't': //edit update time if > 0
            sim.delay = (int)strtol(optarg, NULL, 10);
            printf("Time delay is %d\n", sim.delay);
            break;
        case 'c': //only display numcycles given
            numcycles = (int)strtol(optarg, NULL, 10);
            printf("Numcycles is %d\n", numcycles);
            break;
        case 'd':
            sim.size = (int)strtol(optarg, NULL, 10);
            printf("Dimensions are %d\n", sim.size);
            break;
        case 's':
            sim.strength = (int)strtol(optarg, NULL, 10);
            printf("Strength of preference is %d\n", sim.strength);
            break;
        case 'v':
            sim.vacancy = (int)strtol(optarg, NULL, 10);
            printf("Vacancy is %d\n", sim.vacancy);
            break;
        case 'e':
            sim.end = (int)strtol(optarg, NULL, 10);
            printf("Percent with endline preference is %d\n", sim.end);
            break;
        default:
            fprintf(stderr, "usage:\nbracetopia [-h] [-t N] [-c N] ");
            fprintf(stderr, "[-d dim] [-s %%str] [-v %%vac] [-e %%end]\n");
            return(EXIT_FAILURE);
        }
    }
    printf("Main ends here\n");
}
