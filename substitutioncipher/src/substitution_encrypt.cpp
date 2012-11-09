#include "substitution_encrypt.h"
#include <iostream>

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
