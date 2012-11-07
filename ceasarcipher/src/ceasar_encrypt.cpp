#include "ceasar_encrypt.h"

const unsigned int NO_OF_ALPHABET_LETTERS = 26;

std::string ceasar_encrypt( const std::string & inputString, int shiftValue )
{
    // Make a copy of the input string and work with that
    std::string outputString( inputString );

    // We're working with unsigned char types, so let's constrain the
    // shiftValue right away as to not get overflow for high values
    shiftValue %= NO_OF_ALPHABET_LETTERS;

    for ( unsigned int i = 0; i < outputString.length(); i++ )
    {
        // Convert lower case letters to upper case
        if ( outputString[i] >= 'a' && outputString[i] <= 'z' )
        {
            outputString[i] -= 'a' - 'A';
        }

        char plainTextChar = outputString[i];
        char encryptedChar = plainTextChar;

        // Shift a plaintext letter
        if ( plainTextChar >= 'A' && plainTextChar <= 'Z')
        {
            // Some character shuffling being done here, the end result
            // is the encrypted character, shifted and wrapped around
            // the end of the alphabet if shifted beyond the end
            encryptedChar = (plainTextChar - 'A') + shiftValue;
            encryptedChar %= NO_OF_ALPHABET_LETTERS;
            encryptedChar += 'A';
        }

        outputString[i] = encryptedChar;
    }

    return outputString;
}
