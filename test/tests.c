#include "ctest.h"
#include "generation_alphabet.h"
#include "handling_main_argument.h"

#include <string.h>

CTEST(GENERATION_ALPHABET, ALPHABET_WITH_FLAG)
{
    string alphabet = "";
    int length_alphabet = 0;
    ASSERT_EQUAL(1, generation_alphabet(
            &alphabet,
            NULL,
            false,
            false,
            false,
            false));
    alphabet = "";
    length_alphabet = 0;
    ASSERT_EQUAL(0, generation_alphabet(
            &alphabet,
            &length_alphabet,
            true,
            false,
            false,
            false));
    alphabet = "";
    length_alphabet = 0;
    ASSERT_EQUAL(0, generation_alphabet(
            &alphabet,
            &length_alphabet,
            false,
            true,
            false,
            false));
    alphabet = "";
    length_alphabet = 0;
    ASSERT_EQUAL(0, generation_alphabet(
            &alphabet,
            &length_alphabet,
            false,
            false,
            true,
            false));
    alphabet = "";
    length_alphabet = 0;
    ASSERT_EQUAL(0, generation_alphabet(
            &alphabet,
            &length_alphabet,
            false,
            false,
            false,
            true));
}

CTEST(HANDLING_MAIN_ARGUMENT, CHECK_VALUE_FLAG)
{
    int quantity_argument = 7;
    char** argument = NULL;
    argument = new char*[quantity_argument];
    for(short int i = 1; i < quantity_argument; i++)
    {
        argument[i] = new char[1];
    }
    argument[1][0] = '5';
    argument[2][0] = '3';
    argument[3][0] = '0';
    argument[4][0] = '0';
    argument[5][0] = '0';
    argument[6][0] = '0';
    int quantity_password = 0;
    int length_password = 0;
    bool digit_flag = true;
    bool small_symbol_flag = true;
    bool large_symbol_flag = true;
    bool special_symbol_flag = true;
    handling_main_argument(
            quantity_argument,
            argument,
            &quantity_password,
            &length_password,
            &digit_flag,
            &small_symbol_flag,
            &large_symbol_flag,
            &special_symbol_flag);
    ASSERT_EQUAL(5, quantity_password);
    ASSERT_EQUAL(3, length_password);
    ASSERT_TRUE(digit_flag);
    ASSERT_TRUE(small_symbol_flag);
    ASSERT_TRUE(large_symbol_flag);
    ASSERT_TRUE(special_symbol_flag);
    quantity_password = 0;
    argument[1][0] = 'a';
    ASSERT_EQUAL(1, handling_main_argument(
            quantity_argument,
            argument,
            &quantity_password,
            &length_password,
            &digit_flag,
            &small_symbol_flag,
            &large_symbol_flag,
            &special_symbol_flag));
    ASSERT_EQUAL(0, quantity_password);
    argument[1][0] = '5';
    argument[3][0] = 'd';
    argument[4][0] = 's';
    argument[5][0] = 'l';
    argument[6][0] = 'q';
    ASSERT_EQUAL(0, handling_main_argument(
            quantity_argument,
            argument,
            &quantity_password,
            &length_password,
            &digit_flag,
            &small_symbol_flag,
            &large_symbol_flag,
            &special_symbol_flag));
    ASSERT_FALSE(digit_flag);
    ASSERT_FALSE(small_symbol_flag);
    ASSERT_FALSE(large_symbol_flag);
    ASSERT_FALSE(special_symbol_flag);
    argument[1][0] = 'f';
    ASSERT_EQUAL(1, handling_main_argument(
            quantity_argument,
            argument,
            &quantity_password,
            &length_password,
            &digit_flag,
            &small_symbol_flag,
            &large_symbol_flag,
            &special_symbol_flag));
}