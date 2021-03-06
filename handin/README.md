# INTO-Skil10-EgillOgFreyr

## Copyright

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/3.0/deed.en_US"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by-nc-sa/3.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/3.0/deed.en_US">Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License</a>.

## Introduction

Assignment 10. ENCRYPTION - INTO

Authors:
- Freyr Bergsteinsson <freyrb12@ru.is>
- Egill Bjornsson <egillb12@ru.is>

This project contains two programs that uses known encryption algorithms. One program is called ceasarcipher - it lets let user encrypt and decrypt messages using a [Ceasar cipher](http://en.wikipedia.org/wiki/Caesar_cipher). The other program is called substitutioncipher - it lets the user encrypt and decrypt message using a keyword [subtitution cipher](http://en.wikipedia.org/wiki/Substitution_cipher).

## Hand-in files

- INTO-Skil10-EgillOgFreyr-ceasar.cpp
- INTO-Skil10-EgillOgFreyr-substitution.cpp

These are the files that were handed in for the project. The handin required a single cpp file for each program, so the development source files were merged together to make these files.

## Documentation

Code documentation was generated using [doxygen](http://doxygen.org/) and can be found [here](http://fresnik.com/into/skil10/doc/html/).

## Development

This project was developed using
- Github as a source code repository
- [CxxTest](http://cxxtest.com/) as a unit test framework
- [Doxygen](http://doxygen.org/) for code documentation

The code repository can be found [here](https://github.com/fresnik/INTO-Skil10-EgillOgFreyr).

## Running the programs

### Ceasar cipher

When ceasarcipher is run the user is given three choices:
- Encode a message
- Decode a message
- Quit

#### Encoding

When encoding is selected, the user is next asked for a message to encode, and then the number to use as a shift value for the cipher. The encoded message is then displayed in upper case, and the menu is shown again.

As an example, if the shift value 3 is chosen, then the cipher text is the alphabet shifted by three to the left:

 a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z
---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---
 D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C

Here, the message "attack at dawn" would be encoded to "DWWDFN DW GDZQ".

#### Decoding

When decoding is selected, the user is next asked for a message to decode, and then the number to use as a shift value for the cipher. The decoded message is then displayed in lower case, and the menu is shown again.

As an example, if the shift value 3 is chosen, then the cipher text is the alphabet shifted by three to the right:

 A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z
---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---
 x | y | z | a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w

Here, the message "DWWDFN DW GDZQ" would be decoded to "attack at dawn".

### Substitution cipher

When substitutioncipher is run the user is given three choices:
- Encode a message
- Decode a message
- Quit

#### Encoding

When encoding is selected, the user is next asked for a message to encode, and then a keyphrase to use to create the cipher text. The encoded message is then displayed in upper case.

The cipher text is generated by picking out the unique characters from the keyphrase, one by one, and adding them to the cipher text. When all the characters from the keyphrase have been extracted, the rest of the cipher text is filled with the remaining unused characters of the alphabet. As an example, the keyphrase "SCOOBY DOO" would generate the following cipher text:

 a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z
---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---
 S | C | O | B | Y | D | A | E | F | G | H | I | J | K | L | M | N | P | Q | R | T | U | V | W | X | Z

Here, the message "attack at dawn" would be encoded to "SRRSOH SR BSVK".

#### Decoding

When decoding is selected, the user is next asked for a message to decode, and then a keyphrase to use to create the cipher text. The decoded message is then displayed in lower case.

The cipher text is generated by picking out the unique characters from the keyphrase, one by one, and adding them to the cipher text. When all the characters from the keyphrase have been extracted, the rest of the cipher text is filled with the remaining unused characters of the alphabet. As an example, the keyphrase "SCOOBY DOO" would generate the following cipher text:

 S | C | O | B | Y | D | A | E | F | G | H | I | J | K | L | M | N | P | Q | R | T | U | V | W | X | Z
---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---
 a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z

Here, the message "SRRSOH SR BSVK" would be decoded to "attack at dawn".

