#include "ctest.h"
#include "generation_alphabet.h"

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