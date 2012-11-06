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
        TS_FAIL( "Test not implemented" );
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
        TS_FAIL( "Test not implemented" );
    }
    /// Test encryption with a too high shift value
    void testIncorrectShiftValue(void)
    {
        TS_FAIL( "Test not implemented" );
    }
};
