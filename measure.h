// 
// File: measure.h
// measure.h is an interface for functions that measure the happiness
// and the number of vacant spots
//
// @author Ming Creekmore mec5765
//
// @date 2/24/2022
//
// // // // // // // // // // // // // // // // // // // // // // //

#ifndef MEASURE_H
#define MEASURE_H
#include "definition.h"

/// happiness: returns the average happiness and fills in the unhap and vac
///            arrays with the spots of unhappy agents and vacancies
///
/// @param size       dimensions of grid
/// @param hap_size   size of the happy array to be declared
/// @param sim        the grid of bracetopia
/// @param unhap      array of coordinates of unhappy agents
/// @param vac        array of coordinates of vacant spots
/// @param pref       the strength of preference for similar agents nearby
/// @return           the average happiness
double happiness(int size, int hap_size, char sim[][size], struct coor unhap[], struct coor vac[], double pref);

/// checkvalue: checks whether the neighbor has the same alignment as 
///             the agent we are checking, updating the stats
///
/// @param og         the agent we are checking against
/// @param neigh      the neighbor we are comparing
void checkvalue(char og, char neigh);

/// average: returns the average value given an array of doubles
///
/// @param size      the size of the array
/// @param hap       the array of happiness values
/// @return          the average happiness
double average(int size, double hap[]);

#endif
