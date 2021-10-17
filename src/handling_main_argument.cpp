#include "handling_main_argument.h"

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string.h>

using namespace std;

int handling_main_argument(
        int argc,
        char* argv[],
        int* quantity_password,
        int* length_password,
        bool* digit_flag,
        bool* small_symbol_flag,
        bool* large_symbol_flag,
        bool* special_symbol_flag)
{
    int i = 1;
    int temp = 0;
    if (i == argc) {
        return 0;
    }
    temp = atoi(argv[i]);
    if (temp != 0) {
        *quantity_password = temp;
        i++;
    }
    if (i == argc) {
        return 0;
    }
    temp = atoi(argv[i]);
    if (temp != 0) {
        *length_password = temp;
        i++;
    }
    if (i == argc) {
        return 0;
    }
    if (!strcmp(argv[i], "d")) {
        *digit_flag = false;
        i++;
        if (i == argc) {
            return 0;
        }
    }
    if (!strcmp(argv[i], "s")) {
        *small_symbol_flag = false;
        i++;
        if (i == argc) {
            return 0;
        }
    }
    if (!strcmp(argv[i], "l")) {
        *large_symbol_flag = false;
        i++;
        if (i == argc) {
            return 0;
        }
    }
    if (!strcmp(argv[i], "q")) {
        *special_symbol_flag = false;
        i++;
        if (i == argc) {
            return 0;
        }
    }
    if (i == 1) {
        cout << "Incorrect argument" << endl;
        return 1;
    }
    return 0;
}
