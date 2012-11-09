#include "ceasar_decrypt.h"

static const unsigned int NO_OF_ALPHABET_LETTERS = 26;

std::string ceasar_decrypt( const std::string & inputString, int shiftValue )
{
    std::string outputString;

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
