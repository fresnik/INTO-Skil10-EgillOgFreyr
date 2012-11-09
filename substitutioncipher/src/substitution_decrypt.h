#ifndef SUBSTITUTION_DECRYPT_H
#define SUBSTITUTION_DECRYPT_H

#include <string>

/**
 * \brief Decrypts a string using a keyword substitution cipher
 * \note http://en.wikipedia.org/wiki/Substitution_cipher
 * \param inputString The string to encrypt
 * \param keyphrase The keyphrase to use for the cipher
 * \return The decrypted string
 */
std::string substitution_decrypt( const std::string & inputString,
                                  const std::string & keyphrase );

#endif // SUBSTITUTION_DECRYPT_H
