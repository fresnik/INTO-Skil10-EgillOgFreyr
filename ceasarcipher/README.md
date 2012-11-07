# ceasarcipher

## Description

This program asks the user for a string and a value, *x*, and whether to
encrypt the string or decrypt it. The encryption method uses is the
imfamous [Ceasar cipher](http://en.wikipedia.org/wiki/Caesar_cipher), which, when encrypting, takes each letter of
the alphabet and replaces it with another letter *x* places later in
the alphabet. Here *x* is the value entered by the user. If an
encrypted letter goes beyond the last letter in the alphabet, it
starts again from the beginning.

The same method applies for decoding, except that an ecrypted letter
is replaced with another letter *x* places ahead in the alphabet, and
if the decrypted letter goes beyond the first letter in the alphabet,
it starts again from the end.

## Source files

The source files for the program can be located in the `src` directory.

To compile:

    cd src
    make

To run the program:

    ./ceasarcipher

## Unit tests

The unit tests for the methods used by the program are located in the `tests` directory. We use [cxxtest](http://cxxtest.com/) for our unit tests - make sure you have it installed if you wish to run these test!

To run the unit tests:

    cd tests
    make run
