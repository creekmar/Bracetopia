//
// File: printing.c
// printing.c implements the interface printing.h
//
// @author Ming Creekmore mec5765
//
// @date 2/24/2022
//
// // // // // // // // // // // // // // // // // // //

#include "printing.h"

/// print_sim prints the char 2d array based on the mode it is in
void print_sim(int size, char sim[][size], bool infinite) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(infinite) {
                printw("%c", sim[i][j]);
            }
            else {
                printf("%c", sim[i][j]);
            }
        }
        if(infinite) {
            printw("\n");
        }
        else {
            printf("\n");
        }
    }
}

/// print_info prints the cycle information depending on what mode its in
void print_info(int cycle, int num_moves, double happy, struct sim_state sim) {
    if(sim.infinite) {
        printw("cycle: %d\n", cycle);
        printw("moves this cycle: %d\n", num_moves);
        printw("teams' \"happiness\": %g\n", happy);
        printw("dim: %d, %%strength of preference:  %d%%, %%vacancy:  %d%%, ",
               sim.size, sim.strength, sim.vacancy);
        printw("%%end:  %d%%\n", sim.end);
        printw("Use Control-C to quit.");
    }
    else {
        printf("cycle: %d\n", cycle);
        printf("moves this cycle: %d\n", num_moves);
        printf("teams' \"happiness\": %g\n", happy);
        printf("dim: %d, %%strength of preference:  %d%%, %%vacancy:  %d%%, ",
               sim.size, sim.strength, sim.vacancy);
        printf("%%end:  %d%%\n", sim.end);
    }
}






