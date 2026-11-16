/**************************************************************/
/*
            NUMBER
        A painfully precise mathematical operations library.

        All software distributed against attached MIT license.
        More detailed function usage is given by headers.

        TYPES:
            The library itself differentiates types using the _id system field, 
            which allows the types to be recognized even after being passed as
            raw pointers. Messing with this metadata is a fantastic way to
            segfault your code, so please don't edit this field.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef NUMBER_H
#define NUMBER_H

#define DIGIT_ID 0
#define NUMBER_ID 1
#define FRACTION_ID 2
#define REAL_ID 3

typedef struct digit {
    char _id; // 0
    char VALUE;
} digit;

typedef struct number {
    char _id; // 1
    size_t SIZE;
    struct digit *VALUES;
} number;

typedef struct fraction {
    char _id; // 2
    struct number *A;
    struct number *B;
} fraction;

typedef struct real {
    char _id; // 3
    struct number *DIGITS;
    size_t OFFSET;
} real;

// Digit
struct digit *make_digit(char arg);
int is_digit(digit *target);

void load_digit(char arg, digit *target);
void print_digit(digit *target);

// Number
struct number *make_number(int arg);
int is_number(number *target);

void load_number(int arg, number *target);
void print_number(number *target);
void load_number_str(char *arg, number *target);
void free_number(number *target);

#endif