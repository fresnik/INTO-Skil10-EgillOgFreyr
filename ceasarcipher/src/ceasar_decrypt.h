#ifndef CEASAR_DECRYPT_H
#define CEASAR_DECRYPT_H

#include <string>

/**
 * \brief Decrypts a string using a variable-shift Ceasar cipher
 * \note http://en.wikipedia.org/wiki/Caesar_cipher
 * \param inputString The string to encrypt
 * \param shiftValue The number of letters to shift by
 * \return The decrypted string
 */
std::string ceasar_decrypt( const std::string & inputString, int shiftValue );

#endif // CEASAR_DECRYPT_H
