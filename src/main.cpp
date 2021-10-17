#include "generation_alphabet.h"
#include "generation_password.h"

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    string* password = NULL;
    string alphabet;
    int length_alphabet = 0;
    int check_return = 0;
    int quantity_password = 10;
    int length_password = 8;
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
    check_return = generation_password(
            &password,
            alphabet,
            length_alphabet,
            quantity_password,
            length_password);
    if (check_return != 0) {
        return 1;
    }
    return 0;
}
