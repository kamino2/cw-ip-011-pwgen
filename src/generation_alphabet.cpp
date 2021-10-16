#include "generation_alphabet.h"

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

const string digit_alphabet = "0123456789";
const string small_character = "abcdefghijklmnopqrstuvwxyz";
const string large_character = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string special_symbol = "!@#$^&*?";

const int quantity_digit = 10;
const int quantity_character = 26;
const int quantity_special_symbol = 8;

int generation_alphabet(
        string* alphabet,
        int* length_alphabet,
        bool digit_flag,
        bool small_character_flag,
        bool large_character_flag,
        bool special_symbol_flag)
{
    if (digit_flag) {
        *alphabet += digit_alphabet;
        *length_alphabet += quantity_digit;
    }
    if (small_character_flag) {
        *alphabet += small_character;
        *length_alphabet += quantity_character;
    }
    if (large_character_flag) {
        *alphabet += large_character;
        *length_alphabet += quantity_character;
    }
    if (special_symbol_flag) {
        *alphabet += special_symbol;
        *length_alphabet += quantity_special_symbol;
    }
    return 0;
}