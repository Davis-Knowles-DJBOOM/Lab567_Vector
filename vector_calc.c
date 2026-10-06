/********************************************************************
* @file vector_calc.c
* @brief A simple state machine
* @param int argc - the number of arguments
* @param char* argv[] string of args
* @return - the int return code
* @author Davis Knowles
* @date 9/21/2026
* @version 1.0
* @copyright Copyright (C) 2026 C&E Solutions SP. All Rights Reserved.
*Compile:
* gcc vector_calc.c -o vector_calc
*Run:
* ./vector_calc
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vectors.h"

//struct Vector temp = {0};

struct Vector vector_add(char *vector_one_name, char *vector_two_name){
    struct Vector ans;
    struct Vector v1 = get_vector(vector_one_name);
    struct Vector v2 = get_vector(vector_two_name);
    strcpy(ans.name, "ans");
    ans.x = v1.x + v2.x;
    ans.y = v1.y + v2.y;
    ans.z = v1.z + v2.z;
    return ans;
}

void vector_add_set(char *vector_one_name, char *vector_two_name, char *output_vector_name){
    struct Vector ans = vector_add(vector_one_name, vector_two_name);
    strcpy(ans.name, output_vector_name);
    set_vector(ans.name, ans.x, ans.y, ans.z);
}

//-----
struct Vector vector_sub(char *vector_one_name, char *vector_two_name){
    struct Vector ans;
    struct Vector v1 = get_vector(vector_one_name);
    struct Vector v2 = get_vector(vector_two_name);
    strcpy(ans.name, "ans");
    ans.x = v1.x - v2.x;
    ans.y = v1.y - v2.y;
    ans.z = v1.z - v2.z;
    return ans;
}

void vector_sub_set(char *vector_one_name, char *vector_two_name, char *output_vector_name){
    struct Vector ans = vector_sub(vector_one_name, vector_two_name);
    strcpy(ans.name, output_vector_name);
    set_vector(ans.name, ans.x, ans.y, ans.z);
}

//-----
/*
void vector_dot_set(char *vector_one_name, char *vector_two_name, char *output_vector_name){
    return temp;
}

struct Vector vector_dot(char *vector_one_name, char *vector_two_name){
    return temp;
}
//-----
void vector_cross_set(char *vector_one_name, char *vector_two_name, char *output_vector_name){
    return temp;
}

struct Vector vector_cross(char *vector_one_name, char *vector_two_name){
    return temp;
}
//------
void vector_scalar_set(char *vector_one_name, char *vector_two_name, char *output_vector_name){
    return temp;
}

struct Vector scalar(char *vector_one_name, char *vector_two_name){
    return temp;
}

*/
