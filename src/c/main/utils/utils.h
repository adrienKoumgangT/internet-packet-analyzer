/**
 * @file utils.h
 * @author Adrien Koumgang Tegantchouang (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <errno.h>
#include <math.h>

#include "syscall_errors.h"

#define TAILLE_MAX_NUMBER_CHAR 32

/**
 * @brief Get the char to base hex object
 * 
 * @param number 
 * @return char 
 */
char get_char_to_base_hex(int number) {
    switch (number) {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        case 10:
            return 'a';
        case 11:
            return 'b';
        case 12:
            return 'c';
        case 13:
            return 'd';
        case 14:
            return 'e';
        case 15:
            return 'f';
        default:
            print_error("invalid value!");
            return ' ';
    }
}


/**
 * @brief Get the int value for symbol hex object
 * 
 * @param symbol 
 * @return int 
 */
int get_int_value_for_symbol_hex(char symbol) {
    switch (symbol)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'a':
        return 10;
    case 'b':
        return 11;
    case 'c':
        return 12;
    case 'd':
        return 13;
    case 'e':
        return 14;
    case 'f':
        return 15;
    default:
        print_error("invalid value!");
        return -1;
    }
}


/**
 * @brief convertir un nombre de la base 10 vers une base b
 * 
 * @param number le nombre en base 10 (ce nombre doit etre positif)
 * @param base la base vers laquelle convertir le nombre
 * @return char* le nombre convertir en la base donné en paramètre
 */
char* convert_base_ten_to_b(int number, int base) {
    if(number < 0 || base <= 1) {
        return "";
    }

    if(number == 0) {
        return "0";
    }

    int i, cnt = 0;
    char* remains = (char *) malloc((TAILLE_MAX_NUMBER_CHAR+1) * sizeof(char));
    for(i=0; i<=TAILLE_MAX_NUMBER_CHAR; i++) {
        *(remains + i) = '-';
    }
    int dividende = number;
    while(dividende != 0) {
        int rest = dividende % base;
        *(remains + cnt) = get_char_to_base_hex(rest);
    }
    char* final_value = (char *) malloc((cnt+2) * sizeof(char));
    for(i=0; i<=cnt; i++) {
        *(final_value + i) = *(remains + i);
    }
    *(final_value + cnt+1) = '\0';

    return strrev(final_value);
}


/**
 * @brief convertir un nombre d'une base b vers la base 10
 * 
 * @param number le nombre à convertir en base 10
 * @param base la base à laquelle appartient le nombre à convertir
 * @return int le nombre e base 10
 */
int convert_base_b_to_ten(char* number, int base) {
    if(number == NULL || strlen(number) == 0) {
        print_error("Invalid number");
    }
    if(base <= 1) {
        print_error("The base must be greater than 1");
    }
    
    number = strrev(number);
    int value = 0;
    for(int i=0; i<strlen(number); i++) {
        value += get_int_value_for_symbol_hex(*(number + i)) * (pow(base, i));
    }
    return value;
}


/**
 * @brief converti un nombre d'une base vers une autre base
 * 
 * @param number nombre à convertir
 * @param base1 base de départ
 * @param base2 base d'arrivée
 * @return char* le nombre converti
 */
char* convert_base_b1_to_b2(char* number, int base1, int base2) {
    if(base1 == base2) {
        return number;
    }
    if(base1 == 10) {
        int num = atoi(number);
        return convert_base_ten_to_b(num, base2);
    }
    if(base2 == 10) {
        int result = convert_base_b_to_ten(number, base1);
        char* mystr = (char *) malloc((TAILLE_MAX_NUMBER_CHAR+1) * sizeof(char));
        sprintf(mystr, "%d", result);
        return mystr;
    }
    return convert_base_ten_to_b(convert_base_b_to_ten(number, base1), base2);
}


int count_one(char* number) {
    if(number == NULL || strlen(number) == 0) {
        return 0;
    }
    int count = 0;
    for(int i=0; i<strlen(number); i++) {
        if(*(number + i) == '1') {
            count += 1;
        }
    }
    return count;
}

#endif /* UTILS_H_ */
