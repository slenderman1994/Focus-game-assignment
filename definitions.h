//
// Created by Asus on 26/04/2020.
//

#ifndef UNTITLED17_DEFINITIONS_H
#define UNTITLED17_DEFINITIONS_H


#include <stdio.h>
#include <stdlib.h>
#define ROWS 8
#define COLUMNS 8



struct listNode {
    char data; /* each listNode contains a character */
    struct listNode *nextPtr; /* pointer to next node */
};


struct Board
{
    char myboard[ROWS][COLUMNS];
    int num_pieces;
};

typedef enum age{
    VERY_YOUNG,
    YOUNG,
    ADULT,
    MATURE,
    OLD,
    VERY_OLD
} age ;


typedef struct person {
    char name[20];
    age age_label;
} person;

 //function prototype



#endif //UNTITLED17_DEFINITIONS_H


