/**********************************************************************
Program: <Program 3: Number Filter>
Author: <Pratush Kc>
Date: <11/14/2021>
Time spent: <1 Hour>
Purpose: The purpose of this program is to create a number filter that takes several numbers inputed from 
stdin, removes duplicates and prints a list of all the numberes entered (duplicates not included) in ascending order. 
An important detail is that the rane is from 0 up to 2 billion. This means that there may be up to 2 billion unique 
integers entered. This is an issue with datastructures such as trees because storing all 2 billion integers will 
require at least 8 billion bytes or 8 gigabytes. This uses too much memory. The program below stores the state of each
integer entered as a bit. If there can be up to 2 billion unique numbers, there needs to be 2 billion bits. This can 
be achived using arrays and bitflags like in the previous assignments. In this assignment, an array will hold integers
which will contain 32 bits (sizeof(int)). The array will be used in a way that all the bits are a single bit stream. 
These bits will store whether or not a specific output has been entered (which will be entered using the << operator). 
If using an integer array -> 2,000,000,000 bits / 32 bits = 62,500,000. The array must at the maximum, be able to store
62,500,000 integers. This number multiplied by 4 bytes is 250,000,000 or 250 mega bytes. This method uses far less memory than 
using other data structures that will simply store the integer entered. 
Note: This program needs to keep iterating until the highest entered flag_position. This as a result, large numbers take a much 
longer time to get. 
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[])
{
    
    int flag_position;                                                  /*position to set flag in bit stream of (0-2 billion). This corresponds with the inputed integer.*/
    int maxNumber = 0;                                                  /*holds largest number entered. Will allow for program to execute faster if the range isnt so high. */
    int* arr;                                                           /*array pointer*/
    int i = 0;                                                          /*holds index value of array*/
    int j = 0;                                                          /*iteration variable*/
    int bitShifted;                                                     /*bit shifted by needed amount*/
    int bitVal;                                                         /*stores if bit is either 1 or 0*/
    

    arr = (int*)calloc(62500000, sizeof(int));                          /*Allocate memory for array and initialize to zero*/
                                                                        /*2 billion bits / 32 bits per int = 62,500,000 integers*/
    if (arr == NULL) {
        printf("Error: Unable to allocate memory!\n");
        exit(0);
    }

   

    do {
        fscanf(stdin, "%d", &flag_position);                            /*scan input form standard in*/
        if (flag_position > -1 && flag_position <= 2000000000) {        /*if the integer is valid, set flag*/
            i = flag_position / (sizeof(int)*8);
            bitShifted = 1 << (flag_position % (sizeof(int) * 8));
            arr[i] = arr[i] | bitShifted;                               /*or to set flag*/
            if (flag_position > maxNumber) {                            /*find and set max number. This will cut down on iterations later on*/
                maxNumber = flag_position;
            }
        }

    } while(flag_position != -1);                                       /*Keep looping until -1 has been entered or the maximum number of integers*/

    flag_position = 0;                                                  /*reset flag position*/
    
    for (j = 0; j <= maxNumber; j++) {                                  /*keep iterating until the largest number entered is reached (can be up to 2 billion)*/
                                                                        /*this loop should check all bits between 0 and the largest flag positon*/
        i = flag_position / (sizeof(int) * 8);
        bitShifted = 1 << (flag_position % (sizeof(int) * 8));
        bitVal = arr[i] & bitShifted;                                   /*logical and to get bit value*/
            
        if (bitVal != 0) {                                              /*print the flag position if bit is not 0*/
            fprintf(stdout, "%d\n", flag_position);                     /*print to standard out*/
        }

        flag_position++;                                                /*increment for next iteration*/
    }

    free(arr);                                                          /*free array*/
    return 0;
}

