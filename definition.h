//
// File: definition.h     
// definition.h provides a definition for structs used in project
//
// @author Ming Creekmore mec5765
//
// @date 2/24/2022
//
// // // // // // // // // // // // // // // // // // // // // // // 

#ifndef DEFINITION_H
#define DEFINITION_H
#include <stdbool.h>

/// struct coor    holds coordinate pairs
/// x              the row number
/// y              the column number
struct coor {
    int x;
    int y;
};

/// struct happy   values calculated by happiness function
/// happiness      the average happiness    
/// num_unhappy    the number of agents unhappy
struct happy_values {
    double happiness;
    int unhappy;
};

/// struct sim_state    holds values that define the simulation
/// size                dimensions of the simulation
/// strength            strength of preference to be near like people
/// vacancy             percent of vacant spots open
/// end                 percent of people that prefer endline
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

#endif
