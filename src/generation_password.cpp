#include "generation_password.h"

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int generation_password(
        string** password,
        string alphabet,
        int length_alphabet,
        int quantity_password,
        int length_password)
{
    srand(time(NULL));
    *password = new string[quantity_password];
    if (*password == NULL) {
        return 1;
    }
    for (short int i = 0; i < quantity_password; i++) {
        for (short int j = 0; j < length_password; j++) {
            (*password)[i] += alphabet[rand() % length_alphabet];
        }
        cout << (*password)[i] << endl;
    }
    return 0;
}