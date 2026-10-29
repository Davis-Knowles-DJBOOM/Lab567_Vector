/********************************************************************
* @file vectors.c
* @brief vector storage management
* @return - the int return code
* @author Davis Knowles
* @date 10/15/2026
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
#include "vStruct.h"

#define GROWTH_SIZE 5

//function initializations
int vector_exists(char *name);
Vector *allocate(Vector* ptr, int size);
Vector *reallocate(Vector* ptr, int size);
int deallocate(Vector* ptr);

int vector_count = -1;
int currT_vectors = 10;

Vector *vectors = NULL;

Vector get_vector(int index){
    if(index < 0 || index > vector_count){
        printf("vector index out of bounds\n");
        Vector err = {0};
        return err;
    }
    return vectors[index];
}

Vector find_vector(char *curr_name){
    //printf("%d\n", vector_count);
    //printf("%s\n", curr_name);
    for(int i = 0; i <= vector_count; i++){
        //printf("  %s\n", vectors[i].name);
        if(!strcmp(curr_name, vectors[i].name)){
            return vectors[i];
        }
    }
    printf("vector: %s does not exist\n", curr_name);
    Vector err = {0};
    return err;
}

void set_vector(char *name, double x, double y, double z){
    if(vectors == NULL){
        *vectors = allocate(vectors, currT_vectors);
    }
    Vector vec;
    strcpy(vec.name, name);
    vec.x = x;
    vec.y = y;
    vec.z = z;
    int pos = vector_exists(name);
    if(pos >= 0 && vector_count+1 < 10){
        printf("vector exists updating old values\n");
        *(vectors + pos) = vec;
        printf("%s = (%f, %f, %f)\n", vectors[pos].name, vectors[pos].x, vectors[pos].y, vectors[pos].z);
    } else if (pos == -1 && vector_count+1 < 10){
        vector_count++;
        *(vectors + vector_count) = vec;
        printf("created new vector: ");
        printf("%s = (%f, %f, %f)\n", vectors[vector_count].name, vectors[vector_count].x, vectors[vector_count].y, vectors[vector_count].z);
    } else {
        //error condition
        //printf("vector storage full clear before adding more\n");
        printf("vector storage full reallocating memory\n");
        vectors = reallocate(vectors, currT_vectors);
    }
}

void vectors_clear(){
    vector_count = -1;
    deallocate(vectors);
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

int get_vector_count(){
    return vector_count;
}


// true condition returns index of vector name 
// false condition returns -1
int vector_exists(char *name){
    for(int i = 0; i <= vector_count; i++){
        if(!strcmp(name, vectors[i].name)){
            return i;
        }
    }
    return -1;
}
    //init memory allocation - partially implemented 
    Vector *allocate(Vector* ptr, int size){
    ptr = malloc(size*sizeof(Vector));
    return ptr;
    }
    //dynamic memory allocation - not implemented yet
    Vector *reallocate(Vector* ptr, int size){
        size += GROWTH_SIZE;
        int count = 0;
        Vector *temp = NULL;
        do {
            temp = realloc(ptr, size*sizeof(Vector));
            if(temp == NULL){
                printf("realloc failed - trying again\n");
            }
            count++;
        } while(temp == NULL || count < 5);
        ptr = temp;
        return ptr;
    }
    //dynamic memory allocation - not implemented yet
    int deallocate(Vector* ptr){
        free(ptr);
        if(ptr == NULL){
            return 0;
        } else {
            return 1;
        }
    }