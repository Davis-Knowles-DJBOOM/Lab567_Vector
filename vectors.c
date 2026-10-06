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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vector{
    char name[20];
    double x;
    double y;
    double z;
} Vector;

int vector_count = -1;

struct Vector vectors[10];

int vector_exists(char *name);

struct Vector get_vector(char *name){
    //printf("%d\n", vector_count);
    for(int i = 0; i <= vector_count; i++){
        //printf("%s\n", vectors[i].name);
        if(!strcmp(name, vectors[i].name)){
            return vectors[i];
        }
    }
    printf("vector: %s does not exist", name);
    Vector err = {0};
    return err;
}

void set_vector(char *name, double x, double y, double z){
    struct Vector vec;
    strcpy(vec.name, name);
    vec.x = x;
    vec.y = y;
    vec.z = z;
    int pos = vector_exists(name);
    if(pos >= 0 && pos < 10){
        printf("vector exists updating old values\n");
        vectors[pos] = vec;
    } else if (pos == -1){
        vector_count++;
        vectors[vector_count] = vec;
        printf("created new vector: ");
        printf("%s = (%f, %f, %f)\n", vectors[vector_count].name, vectors[vector_count].x, vectors[vector_count].y, vectors[vector_count].z);
    } else {
        //error condition
        printf("vector storage full clear before adding more\n");
    }
}

void vectors_clear(){
    vector_count = -1;
    printf("vector mem cleared\n");
}

void vectors_list(){
    //checks for if there are no vectors in mem
    if(vector_count < 0){
        printf("no vectors in mem");
    }
    //prints all vectors in mem
    for(int i = 0; i <= vector_count; i++){
        printf("%s = (%f, %f, %f)\n", vectors[i].name, vectors[i].x, vectors[i].y, vectors[i].z);
    }
}


// true condition returns index of vector name 
// false condition returns -1
int vector_exists(char *name){
    for(int i = 0; i < vector_count; i++){
        if(!strcmp(name, vectors[i].name)){
            return i;
        }
    }
    return -1;
}