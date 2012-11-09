/*! \file INTO-Skil10-EgillOgFreyr-substitution.cpp
 *  \brief Encrypts and decrypts messages using a keyword substitution cipher.
 *  \date 9.11.2012
 *  \author Freyr Bergsteinsson <freyrb12@ru.is>
 *  \author Egill Bjornsson <egillb12@ru.is>
 *  \copyright http://creativecommons.org/licenses/by-nc-sa/3.0/
 *
 * INTO Assignment 10: ENCRYPTION
 * ==============================
 * When this program is run, the user will be given the choice to either
 * encrypt a message or decrypt a message. The method used is a keyword
 * [substitution cipher](http://en.wikipedia.org/wiki/Substitution_cipher). After the
 * user has chosen whether to decrypt or encrypt, the user is asked to
 * enter a keyphrase. This is one or more words making up a phrase and is
 * used when creating the cipher text.  After one message has been
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

// Forward delcarations
char choiceMenu();
string getKeyphrase();
std::string substitution_encrypt( const std::string & inputString,
                                  const std::string & keyphrase );
std::string substitution_decrypt( const std::string & inputString,
                                  const std::string & keyphrase );

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

/** \brief Ask the user for the keyphrase to use for encryption or decryption
 *  \return The keyphrase string
 */
string getKeyphrase()
{
    cout << "Enter the keyphrase: ";
    string keyphrase;
    getline( cin, keyphrase );
    return keyphrase;
}

/**
 * \brief Encrypts a string using a keyphrase cipher
 * \note http://en.wikipedia.org/wiki/keyphrase_cipher
 * \param inputString The string to encrypt
 * \param keyphrase The keyphrase to use for the cipher
 * \return The encrypted string
 */
std::string substitution_encrypt( const std::string & inputString,
                                  const std::string & keyphrase )
{
    std::string encryptedText = "";
    std::string cipherUsed = "";

    // Go through the keyphrase and add any non-repeating characters to the cipherUsed string
    for ( unsigned int i = 0; i < keyphrase.length(); i++ )
    {
        char keychar = keyphrase[i];
        // Convert char to lowercase
        if ( keychar >= 'a' && keychar <= 'z' )
        {
            keychar = toupper( keychar );
        }
        if ( keychar >= 'A' && keychar <= 'Z' )
        {
            // If we have a letter in the alphabet that's not already in the
            // cipherUsed string, add it
            if ( cipherUsed.find( keychar ) == std::string::npos )
            {
                cipherUsed.append( 1, keychar );
            }
        }
    }

    // Fill cipherUsed with the rest of the letters of the alphabet that weren't
    // used in the keyphrase
    for ( char c = 'A'; c <= 'Z'; c++ )
    {
        if ( cipherUsed.find( c ) == std::string::npos )
        {
            cipherUsed.append( 1, c );
        }
    }

    // Go through all the characters in the inputString for encryption
    for ( unsigned int i = 0; i < inputString.length(); i++ )
    {
        char encryptedChar = inputString[i];
        if ( encryptedChar >= 'a' && encryptedChar <= 'z' )
        {
            encryptedChar = toupper( encryptedChar );
        }

        if ( encryptedChar >= 'A' && encryptedChar <= 'Z' )
        {
            encryptedChar = cipherUsed[ encryptedChar - 'A' ];
        }

        encryptedText.append( 1, encryptedChar );
    }

    return encryptedText;
}

/**
 * \brief Decrypts a string using a keyphrase cipher
 * \note http://en.wikipedia.org/wiki/keyphrase_cipher
 * \param inputString The string to encrypt
 * \param keyphrase The keyphrase to use for the cipher
 * \return The decrypted string
 */
std::string substitution_decrypt( const std::string & inputString,
                                  const std::string & keyphrase )
{
    std::string decryptedText = "";
    std::string cipherUsed = "";

    // Go through the keyphrase and add any non-repeating characters to the cipherUsed string
    for ( unsigned int i = 0; i < keyphrase.length(); i++ )
    {
        char keychar = keyphrase[i];
        // Convert char to uppercase
        if ( keychar >= 'A' && keychar <= 'Z' )
        {
            keychar = tolower( keychar );
        }
        if ( keychar >= 'a' && keychar <= 'z' )
        {
            // If we have a letter in the alphabet that's not already in the
            // cipherUsed string, add it
            if ( cipherUsed.find( keychar ) == std::string::npos )
            {
                cipherUsed.append( 1, keychar );
            }
        }
    }

    // Fill cipherUsed with the rest of the letters of the alphabet that weren't
    // used in the keyphrase
    for ( char c = 'a'; c <= 'z'; c++ )
    {
        if ( cipherUsed.find( c ) == std::string::npos )
        {
            cipherUsed.append( 1, c );
        }
    }

    // Go through all the characters in the inputString for decryption
    for ( unsigned int i = 0; i < inputString.length(); i++ )
    {
        char decryptedChar = inputString[i];
        if ( decryptedChar >= 'A' && decryptedChar <= 'Z' )
        {
            decryptedChar = tolower( decryptedChar );
        }

        if ( decryptedChar >= 'a' && decryptedChar <= 'z' )
        {
            decryptedChar = cipherUsed.find(decryptedChar) + 'a';
        }

        decryptedText.append( 1, decryptedChar );
    }

    return decryptedText;
}
