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
