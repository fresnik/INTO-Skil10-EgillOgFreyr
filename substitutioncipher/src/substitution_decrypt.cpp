#include "substitution_decrypt.h"

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
