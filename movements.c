// 
// File: movements.c
// Implementation of movements.h
//
// @author Ming Creekmore mec5765
//
// @date 2/24/2022
//
// // // // // // // // // // // // // // // // // // // // //

#define _DEFAULT_SOURCE
#include "movements.h"
#define vt vac[num_moves]
#define uh unhappy[num_moves]

/// shuffle function randomizes an array
void shuffle(int size, char* sim){
    for(int i = size-1; i > 0; i--){
        int j = rand();
        j %= size;
        char tmp = sim[i];
        sim[i] = sim[j];
        sim[j] = tmp;
    }
}

/// moves unhappy agents to the next vacant spot
/// goes until there are no more vacant spots or there are no more unhappy agents
int move(int sim_size, char sim[][sim_size], int hap_size, struct coor unhappy[], int vac_size, struct coor vac[]) {
    int num_moves = 0;
    while(num_moves < hap_size || num_moves < vac_size) {
        sim[vt.x][vt.y] = sim[uh.x][uh.y];
        num_moves++;
    }
    return num_moves;
}
