#include "ceasar_encrypt.h"

static const unsigned int NO_OF_ALPHABET_LETTERS = 26;

std::string ceasar_encrypt( const std::string & inputString, int shiftValue )
{
    // Make a copy of the input string and work with that
    std::string outputString;

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
