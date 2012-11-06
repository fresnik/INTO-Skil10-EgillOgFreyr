#include <cxxtest/TestSuite.h>
#include "ceasar_decrypt.h"

/**
 * \brief Do various test on the ceasar_decrypt() function
 */
class ceasarDecryptTest : public CxxTest::TestSuite
{
public:
	/// Test encryption on all single character strings with a shift of 1
    void testSingleCharsShiftedByOne(void)
    {
        TS_ASSERT_EQUALS( ceasar_decrypt( "B", 1), "a" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "C", 1), "b" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "D", 1), "c" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "E", 1), "d" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "F", 1), "e" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "G", 1), "f" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "H", 1), "g" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "I", 1), "h" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "J", 1), "i" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "K", 1), "j" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "L", 1), "k" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "M", 1), "l" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "N", 1), "m" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "O", 1), "n" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "P", 1), "o" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "Q", 1), "p" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "R", 1), "q" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "S", 1), "r" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "T", 1), "s" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "U", 1), "t" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "V", 1), "u" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "W", 1), "v" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "X", 1), "w" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "Y", 1), "x" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "Z", 1), "y" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 1), "z" );
    }
    /// Test encryption on a en empty string
    void testEmptyString(void)
    {
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 1), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 2), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 3), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 4), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 5), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 6), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 7), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 8), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 9), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 10), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 11), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 12), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 13), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 14), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 15), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 16), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 17), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 18), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 19), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 20), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 21), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 22), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 23), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 24), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 25), "" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "", 26), "" );
    }
    /// Test encryption on a single character shifted by every number
    void testSingleCharShiftedByAll(void)
    {
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 1), "z" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 2), "y" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 3), "x" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 4), "w" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 5), "v" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 6), "u" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 7), "t" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 8), "s" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 9), "r" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 10), "q" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 11), "p" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 12), "o" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 13), "n" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 14), "m" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 15), "l" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 16), "k" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 17), "j" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 18), "i" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 19), "h" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 20), "g" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 21), "f" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 22), "e" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 23), "d" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 24), "c" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "A", 25), "b" );
    }
    /// Test encryption with a too high (>=26) shift value
    void testHighShiftValue(void)
    {
        TS_ASSERT_EQUALS( ceasar_decrypt( "FOO", 26), "foo" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "FOO", 27), "enn" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "FOO", 52), "foo" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "FOO", 53), "enn" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "BAR", 26), "bar" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "BAR", 27), "azq" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "BAR", 52), "bar" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "BAR", 53), "azq" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "SMU", 26), "smu" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "SMU", 27), "rlt" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "SMU", 52), "smu" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "SMU", 53), "rlt" );
    }
    /// Test a string containing all the letters of the alphabet
    void testTheQuickBrownFox(void)
    {
        TS_ASSERT_EQUALS( ceasar_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", 1), "sgd pthbj aqnvm enw itlor nudq sgd kzyx cnf" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", 2), "rfc osgai zpmul dmv hsknq mtcp rfc jyxw bme" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", 3), "qeb nrfzh yoltk clu grjmp lsbo qeb ixwv ald" );
    }
    /// Test lowercase characters
    void testLowerCaseCharacters(void)
    {
        TS_ASSERT_EQUALS( ceasar_decrypt( "foo", 1), "enn" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "foo", 2), "dmm" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "foo", 3), "cll" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "foo", 25), "gpp" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "bar", 1), "azq" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "bar", 2), "zyp" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "bar", 3), "yxo" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "bar", 25), "cbs" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "smu", 1), "rlt" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "smu", 2), "qks" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "smu", 3), "pjr" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "smu", 25), "tnv" );
    }
    /// Test decrypting with a zero value
    void testZeroShiftValue(void)
    {
        TS_ASSERT_EQUALS( ceasar_decrypt( "foo", 0), "foo" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "bar", 0), "bar" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "smu", 0), "smu" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "FOO", 0), "foo" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "BAR", 0), "bar" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "SMU", 0), "smu" );
        TS_ASSERT_EQUALS( ceasar_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", 1), "the quick brown fox jumps over the lazy dog" );
    }
};