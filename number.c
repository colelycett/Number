#include "number.h"

digit *make_digit(char arg) {
    // Argument interpreted as bit value

    digit *new_digit = (digit*)malloc(sizeof(digit));
    new_digit->_id = DIGIT_ID;
    new_digit->VALUE = arg;

    return new_digit;
}

int is_digit(digit *target) {
    if (!target) {
        return 0;
    }
    else if (target->_id != DIGIT_ID) {
        return 0;
    }

    return 1;
}

void load_digit(char arg, digit *target) {
    if (!is_digit(target)) {
        return;
    }
    // Interpreted as bit value
    target->VALUE = arg;
    return;
}

void print_digit(digit *target) {
    if (!is_digit(target)) {
        return;
    }
    // Conversion to ASCII
    char p = target->VALUE + 48;
    printf("%c",p);
    return;
}