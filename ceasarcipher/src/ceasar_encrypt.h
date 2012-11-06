#ifndef CEASAR_ENCRYPT_H
#define CEASAR_ENCRYPT_H

#include <string>

/**
 * \brief Encrypts a string using a variable-shift Ceasar cipher
 * \note http://en.wikipedia.org/wiki/Caesar_cipher
 * \param inputString The string to encrypt
 * \param shiftValue The number of letters to shift by
 * \return The encrypted string
 */
std::string ceasar_encrypt( const std::string & inputString, int shiftValue );

#endif // CEASAR_ENCRYPT_H
