#ifndef SUBSTITUTION_ENCRYPT_H
#define SUBSTITUTION_ENCRYPT_H

#include <string>

/**
 * \brief Encrypts a string using a keyphrase cipher
 * \note http://en.wikipedia.org/wiki/keyphrase_cipher
 * \param inputString The string to encrypt
 * \param keyphrase The keyphrase to use for the cipher
 * \return The encrypted string
 */
std::string substitution_encrypt( const std::string & inputString,
                                  const std::string & keyphrase );

#endif // SUBSTITUTION_ENCRYPT_H
