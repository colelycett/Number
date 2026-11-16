#include "number.h"

digit *make_digit(char arg) {
    // Argument interpreted as bit value
    if (arg >= 48) {
        arg -= 48;
    }

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
    if (arg >= 48) {
        arg -= 48;
    }
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

number *make_number(int arg) {
    number *new_number = (number*)malloc(sizeof(number));
    new_number->_id = NUMBER_ID;
    new_number->SIZE = 0;
    digit *computed_digits = (digit*)malloc(10 * sizeof(digit));
    memset(computed_digits, 0, 10 * sizeof(digit));
    for (int i = 0; i < 10; i++) {
        computed_digits[i]._id = DIGIT_ID;
        load_digit(arg % 10, &computed_digits[i]);
        new_number->SIZE += 1;
        arg /= 10;
        if (arg == 0) {
            break;
        }
    }
    new_number->VALUES = computed_digits;
    return new_number;
}

void free_number(number *target) {
    free(target->VALUES);
    free(target);
    return;
}

void print_number(number *target) {
    for (int i = target->SIZE-1; i >= 0; i--) {
        print_digit(&target->VALUES[i]);
    }
    return;
}

void load_number_str(char *arg, number *target) {
    int len = strlen(arg);
    if (target->SIZE < len) {
        free(target->VALUES);
        target->VALUES = (digit*)malloc(len * sizeof(digit));
        for (int i = 0; i < len; i++) {
            target->VALUES[i]._id = DIGIT_ID;
        }
    }
    target->SIZE = len;
    
    for (int i = len-1; i >= 0; i--) {
        load_digit(arg[i], &target->VALUES[len - i - 1]);
    }
    return;
}