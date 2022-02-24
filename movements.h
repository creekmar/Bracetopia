//
// File: movements.h
// movements.h is an interface for functions that manipulate
// a simulated environment for bracetopia
//
// @author Ming Creekmore mec5765
//
// @date 2/24/2022
//
// // // // // // // // // // // // // // // // // // // // // // 

#ifndef MOVEMENTS_H
#define MOVEMENTS_H
#include <stdlib.h>
#include "definition.h"

/// shuffle: shuffles an array
///
/// @param size         size of the array
/// @param sim          the array to shuffle
void shuffle(int size, char* sim);

/// move: moves unhappy agents to the next available vacant spot
///
/// @param sim_size     dimension of simulation
/// @param sim          simulation of agents in a grid-life form
/// @param hap_size     size of unhappy array
/// @param unhappy      array of coordinates of unhappy agents
/// @param vac_size     size of vacant array
/// @param vac          array of coordinates of vacant spots
/// @return             number of moves made
int smove(int sim_size, char sim[][sim_size], int hap_size, struct coor unhappy[], int vac_size, struct coor vac[]);


#endif
