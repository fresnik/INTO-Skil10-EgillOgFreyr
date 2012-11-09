#include <iostream>
#include "ceasar_encrypt.h"
#include "ceasar_decrypt.h"

using namespace std;

// Forward delcarations
char choiceMenu();
int getShiftValue();

int main()
{
    char menuItemChosen;

    do
    {
        string message;
        int shiftValue;

        menuItemChosen = choiceMenu();
        switch( menuItemChosen )
        {
            case '1':
            {
                cout << "  -  -  -  Enter message to encrypt   -  -  - " << endl;
                getline( cin, message );
                cout << "  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - " << endl << endl;

                shiftValue = getShiftValue();

                cout << endl << "  -  -  -  Encrypted text    -  -  -  -  -  - " << endl;
                cout << ceasar_encrypt( message, shiftValue );
                cout << endl << "  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - " << endl;
            }
                break;
            case '2':
            {
                cout << "  -  -  -  Enter message to decrypt   -  -  -  " << endl;
                getline( cin, message );
                cout << "  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  " << endl << endl;

                shiftValue = getShiftValue();

                cout << endl << "  -  -  -  Decrypted message -  -  -  -  -  - " << endl;
                cout << ceasar_decrypt( message, shiftValue );
                cout << endl << "  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - " << endl;
            }
                break;
            case 'q':
            {
                cout << endl << "  -  -  -  Program closing   -  -  -  -  -  - " << endl;
                break;
            }
        }
    } while ( menuItemChosen != 'q' );

    return 0;
}

/// Displays a menu of choices and gets user input, returns the menu item chosen
char choiceMenu()
{
    char inputChoice;
    cout << "Enter:" << endl
      << "\t1 to encrypt a message" << endl
      << "\t2 to decrypt a message" << endl
      << "\tq to leave the program" << endl;
    do
    {
        cin >> inputChoice;
        cin.ignore( 1024, '\n' );
        inputChoice = tolower( inputChoice );
        if ( inputChoice != '1' && inputChoice != '2' && inputChoice != 'q' )
        {
            cout << "Please enter a valid input (1, 2 or q)!" << endl;
        }
    }
    while ( inputChoice != '1' && inputChoice != '2' && inputChoice != 'q' );
    return inputChoice;
}

/// Ask the user for the number of letters to shift
int getShiftValue()
{
    cout << "Enter shift value: ";
    int shiftValue;
    cin >> shiftValue;
    return shiftValue;
}
