# Lab567_Vector

A vector calculator with dynamic memory allocation and file load and save functionalities.

description:
a vector calculator that can perform vector addition, subtraction, scalar multiplication, division, dot product and cross product. The program has storage for vector types in up to three directions. In addition to having the ability to load and save vectors to and from a csv file.

Bellow are the command formats:
    -h, help  : lists commands
    -q, quit  : quits the program
    -c, clear : clears all vectors stored in memory
    -l, list  : list all vectors in memory
    -lv, load : loads vectors from a csv file
    -sv, save : saves vectors to a csv file
    vName     : gets the value of that vector name
Possible operators
     + : adds two vectors
     - : subtracts two vectos
     . : dot product of the two vectors
     X : cross product of the two vectos
     * : scalar multiplication of the two vectors
Formula formats:
    vName1 = vName2 operator vName3 : sets vector name 1 to the resulting vector of vName2 and vName3
    vName1 operator vName2 : performs operator on both vectors

all calculations functions are called in vectors_calc.c
local vector storage management is done in vectors.c
loading and saving vectors to and from from a csv file is in fileIO.c

The program is built by calling make from the make file.
The program is run by the following command: ./main.exe

the program uses dynamic memory allocation with a global variable in vectors.c with values to track the current count and current max values for the amount of vectors. The program reallocates memory whenever the adding vector reaches the max of the vector storage, deallocating in the clear function in vectors.c which is also called atexit of main.
