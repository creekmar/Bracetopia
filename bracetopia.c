// file: bracetopia.c
// bracetopia is a program that implements a simulator on where agents sit
// in an office and calculates their happiness based on the people sitting
// next to them and whether those other people have the same bracket 
// preferences
// @author Ming Creekmore mec5765
// // // // // // // // // // // // // // // // // // // // // // // // //

#define _DEFAULT_SOURCE

#include <unistd.h>
#include <time.h>
#include <string.h>
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

/// print_error: prints the usage message if bad value
///
/// type         the flag type/variable in sim_state mistyped
/// input        the value inputted
/// num_usage    the type of values expected
void print_error(char* type, int input, char* num_usage) {
    fprintf(stderr, "%s (%d) must be a %s\n", type, input, num_usage);
    fprintf(stderr, "usage: \nbracetopia [-h] [-t N] [-c N] ");
    fprintf(stderr, "[-d dim] [-s %%str] [-v %%vac] [-e %%end]\n");
}

/// main: starts the simulation
///
/// @param argc     the number of arguments
/// @argv[]         list of the arguments
///
/// @return int     exit status
int main(int argc, char* argv[]) {
    int opt;
    //default game_state values
    struct sim_state sim = {15, 50, 20, 60, 900000, 1};
    int numcycles;
    sim.infinite = 1;

    while((opt = getopt(argc, argv, "ht:c:d:s:v:e:")) != -1) {
        int tmp;
        switch(opt){
        case 'h': //help command
            fprintf(stderr, "usage: \nbracetopia [-h] [-t N] [-c N] ");
            fprintf(stderr, "[-d dim] [-s %%str] [-v %%vac] [-e %%end]\n");
            fprintf(stderr, "%-12s%-10s%-10s%s\n", "Option", "Default",
                   "Example", "Description");
            fprintf(stderr, "%-12s%-10s%-10s%s\n", "'-h'", "NA", "-h",
                   "print this usage message.");
            fprintf(stderr, "%-12s%-10s%-10s%s\n", "'-t N'", "900000",
                   "-t 5000", "microseconds cycle delay.");
            fprintf(stderr, "%-12s%-10s%-10s%s\n", "'-c N'", "NA", "-c4",
                   "count cycle maximum value.");
            fprintf(stderr, "%-12s%-10s%-10s%s\n", "'-d dim'", "15", "-d 7",
                   "width and height dimension.");
            fprintf(stderr, "%-12s%-10s%-10s%s\n", "'-s %str'", "50",
                   "-s 30", "strength of preference.");
            fprintf(stderr, "%-12s%-10s%-10s%s\n", "'-v %vac'", "20", 
                   "-v30", "percent vacancies.");
            fprintf(stderr, "%-12s%-10s%-10s%s\n", "'-e %endl'", "60",
                   "-e75", "percent Endline braces. Others want Newline.");
            return EXIT_SUCCESS;
            break;
        case 't': //edit update time if > 0
            tmp = (int)strtol(optarg, NULL, 10);
            if(tmp > 0)
                sim.delay = tmp;
            printf("Time delay is %d\n", sim.delay);
            break;
        case 'c': //only display numcycles given
            tmp = (int)strtol(optarg, NULL, 10);
            if(tmp >= 0)
                numcycles = tmp;
            else {
                print_error("count", tmp, "non-negative integer.");
                return 1 + EXIT_FAILURE;
            }
            printf("Numcycles is %d\n", numcycles);
            break;
        case 'd': //dimension of simulation
            tmp = (int)strtol(optarg, NULL, 10);
            if(tmp > 4 && tmp < 40)
                sim.size = tmp;
            else {
                print_error("dimension", tmp, "value in [5...39]");
                return 1 + EXIT_FAILURE;
            }
            printf("Dimensions are %d\n", sim.size);
            break;
        case 's': //percent strength of preference
            tmp = (int)strtol(optarg, NULL, 10);
            if(tmp > 0 && tmp < 100)
                sim.strength = tmp;
            else {
                print_error("preference strength", tmp, "value in [1...99]");
                return 1 + EXIT_FAILURE;
            }
            printf("Strength of preference is %d\n", sim.strength);
            break;
        case 'v': //percent vacant
            tmp = (int)strtol(optarg, NULL, 10);
            if(tmp > 0 && tmp < 100)
                sim.vacancy = tmp;
            else {
                print_error("vacancy", tmp, "value in [1...99]");
                return 1 + EXIT_FAILURE;
            }
            printf("Vacancy is %d\n", sim.vacancy);
            break;
        case 'e': //percent that prefer endline
            tmp = (int)strtol(optarg, NULL, 10);
            if(tmp > 0 && tmp < 100)
                sim.end = tmp;
            else {
                print_error("endline proportion", tmp, "value in [1...99]");
                return 1 + EXIT_FAILURE;
            }
            printf("Percent with endline preference is %d\n", sim.end);
            break;
        default: // not correct flag
            fprintf(stderr, "usage:\nbracetopia [-h] [-t N] [-c N] ");
            fprintf(stderr, "[-d dim] [-s %%str] [-v %%vac] [-e %%end]\n");
            return EXIT_FAILURE;
        }
    }
    printf("Main ends here\n");
}
