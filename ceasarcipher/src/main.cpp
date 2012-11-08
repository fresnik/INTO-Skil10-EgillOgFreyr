#include <iostream>
#include "ceasar_encrypt.h"
#include "ceasar_decrypt.h"
#include <stdlib.h>
#include <string>
//#include

using namespace std;

char choiceMenu();

int main()
{
    switch(choiceMenu())
    {
        case '1':
        {
            cout<<"  -  -  -  Enter message to encrypt   -  -  -  \n";
            string inputString;
            getline(cin, inputString);
            cout<<"  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  \n\n";
            cout<<"Enter shift value for cypher: ";
            int shift;
            cin>>shift;
            cout<<"\n  -  -  -  encrypted text    -  -  -  -  -  -  \n";
            cout<<ceasar_encrypt(inputString, shift);
            cout<<"\n  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  \n";
        }
            break;
        case '2':
        {
            cout<<"  -  -  -  Enter message to decrypt   -  -  -  \n";
            string inputString;
            getline(cin, inputString);
            cout<<"  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  \n\n";
            cout<<"Enter shift value for decypher: ";
            int shift;
            cin>>shift;
            cout<<"\n  -  -  -  Decryptd message  -  -  -  -  -  -  \n";
            cout<<ceasar_decrypt(inputString, shift);
            cout<<"\n  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  \n";
        }
            break;
        case 'q':
        case 'Q':
            cout<<"\n  -  -  -  Program closing   -  -  -  -  -  -  \n";
            exit(0);
            break;
    }


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
    cout <<"Enter:\n\t1 to encrypt a message \n\t2 to decrypt a message \n\tq to leave the program\n";
    char inputChoice;
    do
    {
        cin >> inputChoice;
        cin.ignore(1024,'\n');
        if(inputChoice!='1' && inputChoice!='2' && inputChoice!='q' && inputChoice!='Q')
            cout<<"Please enter a valid input(1, 2 or q)\n";
    }
    while(inputChoice!='1' && inputChoice!='2' && inputChoice!='q' && inputChoice!='Q');
    return inputChoice;
}
