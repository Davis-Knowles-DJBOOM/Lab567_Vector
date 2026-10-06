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

#ifndef MY_VECTOR_CALC_H
#define MY_VECTOR_CALC_H

#include "vectors.h"

void vector_add_set(char *vector_one_name, char *vector_two_name, char *output_vector_name);

struct Vector vector_add(char *vector_one_name, char *vector_two_name);
//-----
void vector_sub_set(char *vector_one_name, char *vector_two_name, char *output_vector_name);

struct Vector vector_sub(char *vector_one_name, char *vector_two_name);
//-----
/*
void vector_dot_set(char *vector_one_name, char *vector_two_name, char *output_vector_name);

struct Vector vector_dot(char *vector_one_name, char *vector_two_name);
//-----
void vector_cross_set(char *vector_one_name, char *vector_two_name, char *output_vector_name);

struct Vector vector_cross(char *vector_one_name, char *vector_two_name);
//------
void vector_scalar_set(char *vector_one_name, char *vector_two_name, char *output_vector_name);

struct Vector scalar(char *vector_one_name, char *vector_two_name);
*/
#endif