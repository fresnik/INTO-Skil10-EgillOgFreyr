#include <iostream>
#include "substitution_encrypt.h"
#include "substitution_decrypt.h"

using namespace std;

int main()
{
    cout << "Welcome!" << endl;
    cout << substitution_encrypt( "Welcome",
                                  "super mario brothers theme is awesome") << endl;

    // TODO: Display a menu of choices (1 for encrypt, 2 for decrypt, q for quit)
    // TODO: Ask the user for menu choice
    // TODO: If the user chose to quit, exit the program
    // TODO: Ask the user for the string to encrypt/decrypt
    // TODO: Check if input string is legal, keep asking for a new one until it is
    // TODO: Ask the user for the keyphrase to use for encryption/decryption
    // TODO: Check if keyphrase string is legal, keep asking for a new one until it is
    // TODO: If user chose encrypt, call the function substitution_encrypt( inputString, shiftValue )
    // TODO: If user chose decrypt, call the function substitution_decrypt( inputString, shiftValue )
    // TODO: Repeat (?)

    return 0;
}

