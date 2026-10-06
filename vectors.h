/********************************************************************
* @file vectors.c
* @brief A simple state machine
* @param int argc - the number of arguments
* @param char* argv[] string of args
* @return - the int return code
* @author Davis Knowles
* @date 9/21/2026
* @version 1.0
* @copyright Copyright (C) 2026 C&E Solutions SP. All Rights Reserved.
*Compile:
* gcc vectors.c -o vectors
*Run:
* ./vectors
********************************************************************/

#ifndef MYVECTORS_H
#define MYVECTORS_H

typedef struct Vector{
    char name[20];
    double x;
    double y;
    double z;
} Vector;


Vector get_vector(char *name);

void set_vector(char *name, double x, double y, double z);

void vectors_clear();

void vectors_list();

#endif