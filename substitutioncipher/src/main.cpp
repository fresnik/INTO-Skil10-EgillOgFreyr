#include <iostream>
#include "substitution_encrypt.h"
#include "substitution_decrypt.h"

using namespace std;

// Forward delcarations
char choiceMenu();
string getKeyphrase();

int main()
{
    char menuItemChosen;

    do
    {
        string message;
        string keyphrase;

        menuItemChosen = choiceMenu();
        switch( menuItemChosen )
        {
            case '1':
            {
                cout << "  -  -  -  Enter message to encrypt   -  -  - " << endl;
                getline( cin, message );
                cout << "  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - " << endl << endl;

                keyphrase = getKeyphrase();

                cout << endl << "  -  -  -  Encrypted text    -  -  -  -  -  - " << endl;
                cout << substitution_encrypt( message, keyphrase );
                cout << endl << "  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - " << endl;
            }
                break;
            case '2':
            {
                cout << "  -  -  -  Enter message to decrypt   -  -  -  " << endl;
                getline( cin, message );
                cout << "  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  " << endl << endl;

                keyphrase = getKeyphrase();

                cout << endl << "  -  -  -  Decrypted message -  -  -  -  -  - " << endl;
                cout << substitution_decrypt( message, keyphrase );
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

/// Get a keyphrase from the user
string getKeyphrase()
{
    cout << "Enter the keyphrase: ";
    string keyphrase;
    getline( cin, keyphrase );
    return keyphrase;
}
