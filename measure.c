// 
// File: measure.c
// measure.c is an implementation of the interface measure.h
//
// @author Ming Creekmore mec5765
//
// @date 2/24/2022
//
// // // // // // // // // // // // // // // // // // // // // // //

#include "measure.h"
#include "movements.h"
#include <stdio.h>

int same = 0;
int total = 0;

/// happiness measures the happiness of each agent
struct happy_values happiness(int size, int hap_size, char sim[][size], struct coor unhap[], struct coor vac[], double pref) {
    int hap_count = 0;
    int unhap_count = 0;
    int vac_count = 0;
    double happy[hap_size];
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            //only check if the place is occupied
            if(sim[i][j] != '.'){
                //check the neighbors above current grid
                if(i != 0) {
                    checkvalue(sim[i][j], sim[i-1][j]);
                    if(j != 0) {
                        checkvalue(sim[i][j], sim[i-1][j-1]);
                    }
                    if(j != size-1) {
                        checkvalue(sim[i][j], sim[i-1][j+1]);
                    }
                }
                //check the neighbors below the current grid
                if(i != size-1) {
                    checkvalue(sim[i][j], sim[i+1][j]);
                    if(j != 0) {
                        checkvalue(sim[i][j], sim[i+1][j-1]);
                    }
                    if(j != size-1) {
                        checkvalue(sim[i][j], sim[i+1][j+1]);
                    }
                }
                //check the box right and left of the current one
                if(j != 0) {
                    checkvalue(sim[i][j], sim[i][j-1]);
                }
                if(j != size-1) {
                    checkvalue(sim[i][j], sim[i][j+1]);
                }

                //calculating happiness and adding to unhappy
                if(total != 0) {
                    happy[hap_count] = (double) same/total;
                    if(happy[hap_count] < pref) {
                        unhap[unhap_count].x = i;
                        unhap[unhap_count].y = j;
                        unhap_count++;
                    }
                }
                else {
                    happy[hap_count] = 1;
                }
                hap_count++;
                //reset same and total for next neighbor
                same = 0;
                total = 0;
            }

            //if the spot is vacant
            else {
                vac[vac_count].x = i;
                vac[vac_count].y = j;
                vac_count++;
            }

        }//end of first for loop
    }//end of second for loop
    struct happy_values values = {average(hap_count, happy), unhap_count};
    return values;
                
                

}

/// checkvalue function updates the stats of happiness depending on the neighbor
void checkvalue(char og, char neigh) {
    if(neigh != '.') {
        if(og == neigh) {
            same++;
        }
        total++;
    }
}

/// average function returns the average of a list of doubles
double average(int size, double hap[size]) {
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += hap[i];
    }
    return sum/size;
}

