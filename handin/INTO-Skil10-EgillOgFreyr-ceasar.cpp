/*! \file INTO-Skil10-EgillOgFreyr-ceasar.cpp
 *  \brief Encrypts and decrypts messages using a Ceasar cipher.
 *  \date 9.11.2012
 *  \author Freyr Bergsteinsson <freyrb12@ru.is>
 *  \author Egill Bjornsson <egillb12@ru.is>
 *  \copyright http://creativecommons.org/licenses/by-nc-sa/3.0/
 *
 * INTO Assignment 10: ENCRYPTION
 * ==============================
 * When this program is run, the user will be given the choice to either
 * encrypt a message or decrypt a message. The method used is the infamous
 * [Ceasar cipher](http://en.wikipedia.org/wiki/Caesar_cipher). After the
 * user has chosen whether to decrypt or encrypt, the user is asked to
 * enter a shift value. This is the number of letters of the alphabet to
 * shift when creating the cipher text.  After one message has been
 * encrypted or decrypted, the user is asked to repeat the process.
 *
 * Develpment
 * ----------
 * We developed this by using github.com as our version control system,
 * building on what was taught in INTO Assignment 7: Open Source. In
 * addition, we used [CxxTest](http://www.cxxtest.com/) to create unit
 * tests for the encrypt and decrypt methods. The development
 * repository can be found at:
 * - https://github.com/fresnik/INTO-Skil10-EgillOgFreyr
 */

#include <iostream>

using namespace std;

#define NO_OF_ALPHABET_LETTERS 26

// Forward delcarations
char choiceMenu();
int getShiftValue();
string ceasar_encrypt( const string & inputString, int shiftValue );
string ceasar_decrypt( const string & inputString, int shiftValue );

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

/** \brief Displays a menu of choices and gets user input
 *  \return The menu item chosen, as a character
 */
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

/** \brief Ask the user for the number of letters to shift
 *  \return The shift value entered by the user
 */
int getShiftValue()
{
    cout << "Enter shift value: ";
    int shiftValue;
    cin >> shiftValue;
    return shiftValue;
}

/**
 * \brief Encrypts a string using a variable-shift Ceasar cipher
 * \note http://en.wikipedia.org/wiki/Caesar_cipher
 * \param inputString The string to encrypt
 * \param shiftValue The number of letters to shift by
 * \return The encrypted string
 */
string ceasar_encrypt( const string & inputString, int shiftValue )
{
    // Make a copy of the input string and work with that
    string outputString;

    // We're working with unsigned char types, so let's constrain the
    // shiftValue right away as to not get overflow for high values
    shiftValue %= NO_OF_ALPHABET_LETTERS;

    for ( unsigned int i = 0; i < inputString.length(); i++ )
    {
        char encryptedChar = inputString[i];

        // Convert lower case letters to upper case
        if ( encryptedChar >= 'a' && encryptedChar <= 'z' )
        {
            encryptedChar = toupper( encryptedChar );
        }

        // Shift a plaintext letter
        if ( encryptedChar >= 'A' && encryptedChar <= 'Z')
        {
            // Some character shuffling being done here, the end result
            // is the encrypted character, shifted and wrapped around
            // the end of the alphabet if shifted beyond the end
            encryptedChar = (encryptedChar - 'A') + shiftValue;
            encryptedChar %= NO_OF_ALPHABET_LETTERS;
            encryptedChar += 'A';
        }

        outputString.append( 1, encryptedChar );
    }
    return outputString;
}

/**
 * \brief Decrypts a string using a variable-shift Ceasar cipher
 * \note http://en.wikipedia.org/wiki/Caesar_cipher
 * \param inputString The string to encrypt
 * \param shiftValue The number of letters to shift by
 * \return The decrypted string
 */
string ceasar_decrypt( const string & inputString, int shiftValue )
{
    string outputString;

    // We're working with unsigned char types, so let's constrain the
    // shiftValue right away as to not get overflow for high values
    shiftValue %= NO_OF_ALPHABET_LETTERS;

    for ( unsigned int i = 0; i < inputString.length(); i++)
    {
        char decryptedChar = inputString[i];

        // Convert lower case letters to upper case
        if ( decryptedChar >= 'A' && decryptedChar <= 'Z' )
        {
            decryptedChar = tolower( decryptedChar );
        }

        // Shift a plaintext letter
        if ( decryptedChar >= 'a' && decryptedChar <= 'z')
        {

            // Some character shuffling being done here, the end result
            // is the decrypted character, shifted and wrapped around
            // the end of the alphabet if shifted beyond the end
            decryptedChar = (decryptedChar - 'a') - shiftValue + NO_OF_ALPHABET_LETTERS;
            decryptedChar %= NO_OF_ALPHABET_LETTERS;
            decryptedChar += 'a';
        }
        outputString.append( 1, decryptedChar );
    }
    return outputString;
}
