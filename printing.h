//
// File: printing.h
// printing.h is an interface for functions that aid in printing out the
// simulated environment for bracetopia
//
// @author Ming Creekmore mec5765
// 
// @date 2/24/2022
//
// // // // // // // // // // // // // // // // // // // // // // // // //

#ifndef PRINTING_H
#define PRINTING_H
#include <ncurses.h>
#include <stdio.h>
#include "definition.h"

/// print_sim: prints the current simulation values for either mode
///
/// size       the dimension of the simulation grid
/// sim        the simulation grid of bracetopia
/// infinite   whether we are printing in curses (infinite) or 
///            standard output (finite)
void print_sim(int size, char sim[][size], bool infinite);

/// print_info: prints the information of the simulation for the cycle
///
/// cycle       the cycle number the simulation is on
/// num_moves   the number of moves made 
/// happy       the average happiness of all agents in this cycle
/// sim         the state values for the simulation
void print_info(int cycle, int num_moves, double happy, struct sim_state sim);

#endif
