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

#endif
