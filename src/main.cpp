#include "generation_alphabet.h"

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    string alphabet;
    int length_alphabet;
    int check_return = 0;
    bool digit_flag = true;
    bool small_symbol_flag = true;
    bool large_symbol_flag = true;
    bool special_symbol_flag = true;
    check_return = generation_alphabet(
            &alphabet,
            &length_alphabet,
            digit_flag,
            small_symbol_flag,
            large_symbol_flag,
            special_symbol_flag);
    if (check_return != 0) {
        return 1;
    }
    return 0;
}
