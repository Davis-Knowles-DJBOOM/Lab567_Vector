/********************************************************************
* @file vector_calc.c
* @brief vector calculations
* @param int argc - the number of arguments
* @param char* argv[] string of args
* @return - the int return code
* @author Davis Knowles
* @date 10/15/2026
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
#include "vStruct.h"

//adds two vectors
Vector vector_add(char *vector_one_name, char *vector_two_name){
    Vector ans;
    Vector v1 = find_vector(vector_one_name);
    Vector v2 = find_vector(vector_two_name);
    strcpy(ans.name, "ans");
    ans.x = v1.x + v2.x;
    ans.y = v1.y + v2.y;
    ans.z = v1.z + v2.z;
    return ans;
}
//calls vector_add and sets vector
void vector_add_set(char *vector_one_name, char *vector_two_name, char *output_vector_name){
    Vector ans = vector_add(vector_one_name, vector_two_name);
    strcpy(ans.name, output_vector_name);
    set_vector(ans.name, ans.x, ans.y, ans.z);
}

//subtracts two vectors
Vector vector_sub(char *vector_one_name, char *vector_two_name){
    Vector ans;
    Vector v1 = find_vector(vector_one_name);
    Vector v2 = find_vector(vector_two_name);
    strcpy(ans.name, "ans");
    ans.x = v1.x - v2.x;
    ans.y = v1.y - v2.y;
    ans.z = v1.z - v2.z;
    return ans;
}
//calls vector_sub and sets vector
void vector_sub_set(char *vector_one_name, char *vector_two_name, char *output_vector_name){
    Vector ans = vector_sub(vector_one_name, vector_two_name);
    strcpy(ans.name, output_vector_name);
    set_vector(ans.name, ans.x, ans.y, ans.z);
}

//computes dot product for two vectors
Vector vector_dot(char *vector_one_name, char *vector_two_name){
    Vector ans;
    Vector v1 = find_vector(vector_one_name);
    Vector v2 = find_vector(vector_two_name);
    strcpy(ans.name, "ans");
    ans.x = v1.x * v2.x;
    ans.y = v1.y * v2.y;
    ans.z = v1.z * v2.z;
    ans.x = ans.x + ans.y + ans.z;
    ans.y = 0;
    ans.z = 0;
    return ans;
}
//calls vector_dot and sets vector
void vector_dot_set(char *vector_one_name, char *vector_two_name, char *output_vector_name){
    Vector ans = vector_dot(vector_one_name, vector_two_name);
    strcpy(ans.name, output_vector_name);
    set_vector(ans.name, ans.x, ans.y, ans.z);
}

//calculates cross product for two vectors
Vector vector_cross(char *vector_one_name, char *vector_two_name){
    Vector ans;
    Vector v1 = find_vector(vector_one_name);
    Vector v2 = find_vector(vector_two_name);
    strcpy(ans.name, "ans");
    ans.x = (v1.y * v2.z) - (v1.z * v2.y);
    ans.y = (v1.z * v2.x) - (v1.x * v2.z);
    ans.z = (v1.x * v2.y) - (v1.y * v2.x);
    return ans;
}
//calls vector_cross and sets vector
void vector_cross_set(char *vector_one_name, char *vector_two_name, char *output_vector_name){
    Vector ans = vector_cross(vector_one_name, vector_two_name);
    strcpy(ans.name, output_vector_name);
    set_vector(ans.name, ans.x, ans.y, ans.z);
}

//multiplies vector by scalar
Vector vector_scalar(char *vector_one_name, double scalar){
    Vector ans;
    Vector v1 = find_vector(vector_one_name);
    strcpy(ans.name, "ans");
    ans.x = v1.x * scalar;
    ans.y = v1.y * scalar;
    ans.z = v1.z * scalar;
    return ans;
}
//calls vector_scalar and sets vector
void vector_scalar_set(char *vector_one_name, double scalar, char *output_vector_name){
    Vector ans = vector_scalar(vector_one_name, scalar);
    strcpy(ans.name, output_vector_name);
    set_vector(ans.name, ans.x, ans.y, ans.z);
}



