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
#include "vectors.h"
#include "vStruct.h"


int load_file(char *filename){
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    do{
        Vector vec;
        int result = fscanf(file, "%[^,], %lf, %lf, %lf\n", vec.name, &vec.x, &vec.y, &vec.z);
        printf("result: %d\n", result);
        if (result == 4) {
            set_vector(vec.name, vec.x, vec.y, vec.z);
        } else {
            printf("Error reading vector data from file: %s\n", filename);
            fclose(file);
            return 1; // Exit the loop if reading fails
        }
    } while (!feof(file));

    // Read vector data from file
    fclose(file);
    return 0;
}

int save_file(char *filename){
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        fclose(file);
        return 1;
    }
    char *name = NULL;
    double x = 0.0, y = 0.0, z = 0.0;

    for (int i = 0; i <= get_vector_count(); i++) {
        name = get_vector(i).name;
        x = get_vector(i).x;
        y = get_vector(i).y;
        z = get_vector(i).z;
        fprintf(file, "%s, %f, %f, %f\n", name, x, y, z);
    }
    printf("vectors saved to file: %s\n", filename);

    // Write vector data to file
    fclose(file);
    return 0;
}