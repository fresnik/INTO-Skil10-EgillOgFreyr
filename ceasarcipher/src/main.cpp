#include <iostream>
#include "ceasar_encrypt.h"
#include "ceasar_decrypt.h"
#include <stdlib.h>
//#include

using namespace std;

char choiceMenu();

int main()
{
    choiceMenu();
    cout << "Welcome!" << endl;

    //X TODO: Display a menu of choices (1 for encrypt, 2 for decrypt, q for quit)
    //X TODO: Ask the user for menu choice
    //X TODO: If the user chose to quit, exit the program
    // TODO: Ask the user for the number of letters to shift
    // TODO: Ask the user for the string to encrypt/decrypt
    // TODO: Check if input string is legal, keep asking for a new one until it is
    // TODO: If user chose encrypt, call the function ceasar_encrypt( inputString, shiftValue )
    // TODO: If user chose decrypt, call the function ceasar_decrypt( inputString, shiftValue )
    // TODO: Repeat (?)

    return 0;
}

char choiceMenu()
{
    cout <<"Enter 1 to encrypt a message, 2 to decrypt a message or q to leave the program.";
    char inputChoice;
    do
    {
        cin >> inputChoice;
        if(inputChoice!='1' && inputChoice!='2' && inputChoice!='q')
            cout<<"Please enter a valid input(1, 2 or q)\n";
    }
    while(inputChoice!='1' && inputChoice!='2' && inputChoice!='q');
    if(inputChoice=='q')
        exit(EXIT_FAILURE);
    return inputChoice;
}

