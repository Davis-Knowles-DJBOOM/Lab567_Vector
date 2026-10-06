/********************************************************************
* @file assignment.c
* @brief A simple state machine
* @param int argc - the number of arguments
* @param char* argv[] string of args
* @return - the int return code
* @author Davis Knowles
* @date 9/21/2026
* @version 1.0
* @copyright Copyright (C) 2026 C&E Solutions SP. All Rights Reserved.
*Compile:
* gcc main.c vector_calc.c -o main
*Run:
* ./main
********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "vector_calc.h"
#include "vectors.h"

void all_to_upper(char *str);
void replace_char(char *str, char old, char new);


int main ( int argc, char* argv[]){

    

    int has_quit = 0;
    char user_input[80];
    char *token1;   //vector name - function call (q, h, ect) - output vector
    char *token2;   // operator
    char *token3;   // vector name - first vector value (x)
    char *token4;   // operator - (y)
    char *token5;   // vector name - (z)


    while(!has_quit){
        printf("Enter a vector command or -h for help:\n");
        fgets(user_input, 80, stdin);
        
        all_to_upper(user_input);
        replace_char(user_input, '\n', '\0');
        //replace_char(user_input, '(', '\0');
        //replace_char(user_input, ')', '\0');
        //replace_char(user_input, ',', '\0');
        //replace_char(user_input, '', '\0');
        
        token1 = strtok(user_input," ");
        token2 = strtok(NULL," ");
        token3 = strtok(NULL," ");
        token4 = strtok(NULL," ");
        token5 = strtok(NULL," ");
        
        //printf("\n%s\n%s\n%s\n%s\n%s\n\n", token1, token2, token3, token4, token5);

        //commands
        if(token1 != NULL){
            if(!strcmp(token1,"QUIT") || !strcmp(token1,"-Q")){  //quit
                printf("exiting...\n");
                has_quit = 1;
            } else if(!strcmp(token1 ,"HELP") || !strcmp(token1,"-H")){ //help
                printf("These are all the commands:\n\
    -h, help  : lists commands\n\
    -q, quit  : quits the program\n\
    -c, clear : clears all vectors stored in memory\n\
    -l, list  : list all vectors in memory\n\
    vName     : gets the value of that vector name\n\
    \n\
    Possible operators\n\
     + : adds two vectors
     - : subtracts two vectos
     . : dot product of the two vectors
     X : cross product of the two vectos
     * : scalar multiplication of the two vectors
    \n\
    Formula formats:\n\
    vName1 = vName2 operator vName3 : sets vector name 1 to the resulting vector of vName2 and vName3\n\
    vName1 operator vName2 : performs operator on both vectors\n");
            } else if(!strcmp(token1 ,"CLEAR") || !strcmp(token1,"-C")){ //clear
                //clear vectors
                vectors_clear();
                printf("all saved vectors cleared\n");
            } else if(!strcmp(token1 ,"LIST") || !strcmp(token1,"-L")){    //list
                //list all vectors
                vectors_list();
            } else if(token2 == NULL){    //get vector
                //fetch vector by name if token 2 isn't an operator
                Vector temp_ans = get_vector(token1);
                printf("%s = (%f, %f, %f)\n", temp_ans.name, temp_ans.x, temp_ans.y, temp_ans.z);
            
            } else if(token2 != NULL){
                if(!strcmp(token2, "=") && (strcmp(token4, "+") || strcmp(token4, "-") || strcmp(token4, ".") || strcmp(token4, "*") || strcmp(token4, "X"))){    //assignment
                    //set vector
                    set_vector(token1, atof(token3), atof(token4), atof(token5));
                
                } else if(token3 != NULL){  //operations no set
                    Vector temp_ans = {0};
                    if(!strcmp(token2, "+")){    //operation +
                        //add vectors
                        temp_ans = vector_add(token1, token3);
                        printf("%s = (%f, %f, %f)\n", temp_ans.name, temp_ans.x, temp_ans.y, temp_ans.z);
                        
                    } else if(!strcmp(token2, "-")){    //operation -
                        //sub vectors
                        printf("this happened\n");   
                        temp_ans = vector_sub(token1, token3);    
                        
                    } else if(!strcmp(token2, ".")){    //operation dot
                        //dot product of vectors                        
                        //vector_dot(vector_one_name, vector_two_name);
                        
                    } else if(!strcmp(token2, "X")){    //operation cross
                        //cross product vectors                        
                        //vector_cross(vector_one_name, vector_two_name);

                    } else if(!strcmp(token2, "*")){    //scalar multi
                        //scalar multi                        
                        //vector_scalar(vector_one_name, vector_two_name);                        
                    }
                    printf("%s = (%f, %f, %f)\n", temp_ans.name, temp_ans.x, temp_ans.y, temp_ans.z);
                    
                } else if(token4 != NULL && !strcmp(token2, "=")){  //operations with set
                    if(!strcmp(token4, "+")){    //operation +
                        //add vectors                        
                        vector_add_set(token3, token5, token1);                             
                    } else if(!strcmp(token4, "-")){    //operation -
                        //sub vectors                        
                        vector_sub_set(token3, token5, token1);
                        
                    } else if(!strcmp(token4, ".")){    //operation dot
                        //dot product of vectors                        
                        //vector_dot_set(token3, token5, token1);
                        
                    } else if(!strcmp(token4, "X")){    //operation cross
                        //cross product vectors                        
                        //vector_cross_set(token3, token5, token1);
                        
                    } else if(!strcmp(token4, "*")){    //scalar multi
                        //scalar multi
                        //vector_scalar_set(token3, token5, token1);
                    }
                } else {
                    //error condition
                    printf("error condition\n");
                }
            }
        } else {
            //error condition
            printf("error condition\n");
        }

    };
    return 0;


}

    void replace_char(char *str, char old, char new){
        for(int i = 0; *(str+i) != '\0'; i++){
            if(*(str+i) == old){
                *(str+i) = new;
            }
        }
    }

    void all_to_upper(char *str){
        for(int i = 0; *(str+i) != '\0'; i++){
            *(str+i) = toupper((unsigned char) *(str+i));
        }
    }
