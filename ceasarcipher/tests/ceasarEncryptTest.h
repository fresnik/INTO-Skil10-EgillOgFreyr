#include <cxxtest/TestSuite.h>
#include "ceasar_encrypt.h"

/**
 * \brief Do various test on the ceasar_encrypt() function
 */
class ceasarEncryptTest : public CxxTest::TestSuite
{
public:
	/// Test encryption on all single character strings with a shift of 1
    void testSingleCharsShiftedByOne(void)
    {
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 1), "B" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "b", 1), "C" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "c", 1), "D" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "d", 1), "E" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "e", 1), "F" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "f", 1), "G" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "g", 1), "H" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "h", 1), "I" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "i", 1), "J" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "j", 1), "K" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "k", 1), "L" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "l", 1), "M" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "m", 1), "N" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "n", 1), "O" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "o", 1), "P" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "p", 1), "Q" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "q", 1), "R" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "r", 1), "S" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "s", 1), "T" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "t", 1), "U" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "u", 1), "V" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "v", 1), "W" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "w", 1), "X" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "x", 1), "Y" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "y", 1), "Z" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "z", 1), "A" );
    }
    /// Test encryption on a en empty string
    void testEmptyString(void)
    {
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 1), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 2), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 3), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 4), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 5), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 6), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 7), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 8), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 9), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 10), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 11), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 12), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 13), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 14), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 15), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 16), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 17), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 18), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 19), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 20), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 21), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 22), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 23), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 24), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 25), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 26), "" );
    }
    /// Test encryption on a single character shifted by every number
    void testSingleCharShiftedByAll(void)
    {
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 1), "B" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 2), "C" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 3), "D" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 4), "E" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 5), "F" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 6), "G" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 7), "H" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 8), "I" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 9), "J" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 10), "K" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 11), "L" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 12), "M" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 13), "N" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 14), "O" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 15), "P" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 16), "Q" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 17), "R" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 18), "S" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 19), "T" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 20), "U" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 21), "V" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 22), "W" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 23), "X" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 24), "Y" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 25), "Z" );
    }
    /// Test encryption with a too high (>=26) shift value
    void testHighShiftValue(void)
    {
        TS_ASSERT_EQUALS( ceasar_encrypt( "foo", 26), "FOO" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "foo", 27), "GPP" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "foo", 52), "FOO" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "foo", 53), "GPP" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "bar", 26), "BAR" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "bar", 27), "CBS" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "bar", 52), "BAR" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "bar", 53), "CBS" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "smu", 26), "SMU" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "smu", 27), "TNV" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "smu", 52), "SMU" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "smu", 53), "TNV" );
    }
    /// Test a string containing all the letters of the alphabet
    void testTheQuickBrownFox(void)
    {
        TS_ASSERT_EQUALS( ceasar_encrypt( "the quick brown fox jumps over the lazy dog", 1), "UIF RVJDL CSPXO GPY KVNQT PWFS UIF MBAZ EPH" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", 2), "VJG SWKEM DTQYP HQZ LWORU QXGT VJG NCBA FQI" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", 3), "WKH TXLFN EURZQ IRA MXPSV RYHU WKH ODCB GRJ" );
    }
    /// Test uppercase characters
    void testUpperCaseCharacters(void)
    {
        TS_ASSERT_EQUALS( ceasar_encrypt( "FOO", 1), "GPP" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "FOO", 2), "HQQ" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "FOO", 3), "IRR" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "FOO", 25), "ENN" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "BAR", 1), "CBS" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "BAR", 2), "DCT" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "BAR", 3), "EDU" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "BAR", 25), "AZQ" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "SMU", 1), "TNV" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "SMU", 2), "UOW" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "SMU", 3), "VPX" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "SMU", 25), "RLT" );
    }
    /// Test encrypting with a zero value
    void testZeroShiftValue(void)
    {
        TS_ASSERT_EQUALS( ceasar_encrypt( "", 0), "" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "a", 0), "A" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "A", 0), "A" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "foo", 0), "FOO" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "bar", 0), "BAR" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "smu", 0), "SMU" );
        TS_ASSERT_EQUALS( ceasar_encrypt( "the quick brown fox jumps over the lazy dog", 0), "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG" );
    }
    /// Test illegal characters
    void testIllegalCharacters(void)
    {
        TS_ASSERT_EQUALS( ceasar_encrypt( " ,.!\"#$%&/()=_-'+?*:;áéýúíóþæðöwxyÁÉÝÚÍÓÞÆÐÖ", 3), " ,.!\"#$%&/()=_-'+?*:;áéýúíóþæðöZABÁÉÝÚÍÓÞÆÐÖ" );
    }
};
