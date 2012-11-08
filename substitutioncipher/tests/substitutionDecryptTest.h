#include <cxxtest/TestSuite.h>
#include "substitution_decrypt.h"

/**
 * \brief Do various test on the substitution_decrypt() function
 */
class substitutionDecryptTest : public CxxTest::TestSuite
{
public:
    void setup(void)
    {
        // Keyphrase array includes:
        // 26 keyphrases of different lengths
        // Keyphrase with illegal characters only
        // Keyphrase with illegal characters with lowercase alphabetic characters
        // Keyphrase with illegal characters with uppercase alphabetic characters
        // Keyphrase with illegal characters with mixedcase alphabetic characters
        // 4 keyphrases with uppercase alphabetic characters only
        // 4 keyphrases with mixedcase alphabetic characters
        m_keyphrases.push_back( "t" );
        m_keyphrases.push_back( "th" );
        m_keyphrases.push_back( "the" );
        m_keyphrases.push_back( "the q" );
        m_keyphrases.push_back( "the qu" );
        m_keyphrases.push_back( "the qui" );
        m_keyphrases.push_back( "the quic" );
        m_keyphrases.push_back( "the quick" );
        m_keyphrases.push_back( "the quick b" );
        m_keyphrases.push_back( "the quick br" );
        m_keyphrases.push_back( "the quick bro" );
        m_keyphrases.push_back( "the quick brow" );
        m_keyphrases.push_back( "the quick brown" );
        m_keyphrases.push_back( "the quick brown f" );
        m_keyphrases.push_back( "the quick brown fox" );
        m_keyphrases.push_back( "the quick brown fox j" );
        m_keyphrases.push_back( "the quick brown fox jum" );
        m_keyphrases.push_back( "the quick brown fox jump" );
        m_keyphrases.push_back( "the quick brown fox jumps" );
        m_keyphrases.push_back( "the quick brown fox jumps ov" );
        m_keyphrases.push_back( "the quick brown fox jumps over the l" );
        m_keyphrases.push_back( "the quick brown fox jumps over the la" );
        m_keyphrases.push_back( "the quick brown fox jumps over the laz" );
        m_keyphrases.push_back( "the quick brown fox jumps over the lazy" );
        m_keyphrases.push_back( "the quick brown fox jumps over the lazy d" );
        m_keyphrases.push_back( "the quick brown fox jumps over the lazy dog" );
        m_keyphrases.push_back( " ,.!\"#$%&/()=_-'+?*:;áéýúíóþæðöÁÉÝÚÍÓÞÆÐÖ" );
        m_keyphrases.push_back( " ,.!\"#$%&/()=_-'+?*:;abcxyzáéýúíóþæðöÁÉÝÚÍÓÞÆÐÖ" );
        m_keyphrases.push_back( " ,.!\"#$%&/()=_-'+?*:;ABCXYZáéýúíóþæðöÁÉÝÚÍÓÞÆÐÖ" );
        m_keyphrases.push_back( " ,.!\"#$%&/()=_-'+?*:;ABCxyzáéýúíóþæðöÁÉÝÚÍÓÞÆÐÖ" );
        m_keyphrases.push_back( "T" );
        m_keyphrases.push_back( "TH" );
        m_keyphrases.push_back( "THE QUICK BROWN FOX JUMPS OVER THE LAZY D" );
        m_keyphrases.push_back( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG" );
        m_keyphrases.push_back( "THE quick" );
        m_keyphrases.push_back( "THE QUICK brown fox" );
        m_keyphrases.push_back( "THE QUICK BROWN FOX jumps over the lazy d" );
        m_keyphrases.push_back( "THE QUICK BROWN FOX JUMPS over the lazy dog" );
     }

	/// Test decryption on all single character strings with the same keyphrase
    void testSingleCharsSameKeyphrase(void)
    {
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[25]), "t" );
        TS_ASSERT_EQUALS( substitution_decrypt( "B", m_keyphrases[25]), "h" );
        TS_ASSERT_EQUALS( substitution_decrypt( "C", m_keyphrases[25]), "e" );
        TS_ASSERT_EQUALS( substitution_decrypt( "D", m_keyphrases[25]), "q" );
        TS_ASSERT_EQUALS( substitution_decrypt( "E", m_keyphrases[25]), "u" );
        TS_ASSERT_EQUALS( substitution_decrypt( "F", m_keyphrases[25]), "i" );
        TS_ASSERT_EQUALS( substitution_decrypt( "G", m_keyphrases[25]), "c" );
        TS_ASSERT_EQUALS( substitution_decrypt( "H", m_keyphrases[25]), "k" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[25]), "b" );
        TS_ASSERT_EQUALS( substitution_decrypt( "J", m_keyphrases[25]), "r" );
        TS_ASSERT_EQUALS( substitution_decrypt( "K", m_keyphrases[25]), "o" );
        TS_ASSERT_EQUALS( substitution_decrypt( "L", m_keyphrases[25]), "w" );
        TS_ASSERT_EQUALS( substitution_decrypt( "M", m_keyphrases[25]), "n" );
        TS_ASSERT_EQUALS( substitution_decrypt( "N", m_keyphrases[25]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "O", m_keyphrases[25]), "x" );
        TS_ASSERT_EQUALS( substitution_decrypt( "P", m_keyphrases[25]), "j" );
        TS_ASSERT_EQUALS( substitution_decrypt( "Q", m_keyphrases[25]), "m" );
        TS_ASSERT_EQUALS( substitution_decrypt( "R", m_keyphrases[25]), "p" );
        TS_ASSERT_EQUALS( substitution_decrypt( "S", m_keyphrases[25]), "s" );
        TS_ASSERT_EQUALS( substitution_decrypt( "T", m_keyphrases[25]), "v" );
        TS_ASSERT_EQUALS( substitution_decrypt( "U", m_keyphrases[25]), "l" );
        TS_ASSERT_EQUALS( substitution_decrypt( "V", m_keyphrases[25]), "a" );
        TS_ASSERT_EQUALS( substitution_decrypt( "W", m_keyphrases[25]), "z" );
        TS_ASSERT_EQUALS( substitution_decrypt( "X", m_keyphrases[25]), "y" );
        TS_ASSERT_EQUALS( substitution_decrypt( "Y", m_keyphrases[25]), "d" );
        TS_ASSERT_EQUALS( substitution_decrypt( "Z", m_keyphrases[25]), "g" );
    }
    /// Test decryption on a en empty string using various keyphrases
    void testEmptyString(void)
    {
        TS_FAIL( "Test not implemented" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[0]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[1]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[2]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[3]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[4]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[5]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[6]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[7]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[8]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[9]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[10]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[11]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[12]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[13]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[14]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[15]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[16]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[17]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[18]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[19]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[20]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[21]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[22]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[23]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[24]), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[25]), "" );
    }
    /// Test decryption on a single character using various keyphrases
    void testSingleCharShiftedByAll(void)
    {
        TS_FAIL( "Test not implemented" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[0]), "b" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[1]), "z" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[2]), "y" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[3]), "x" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[4]), "w" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[5]), "v" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[6]), "u" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[7]), "t" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[8]), "s" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[9]), "r" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[10]), "q" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[11]), "p" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[12]), "o" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[13]), "n" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[14]), "m" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[15]), "l" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[16]), "k" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[17]), "j" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[18]), "i" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[19]), "h" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[20]), "g" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[21]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[22]), "e" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[23]), "d" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[24]), "c" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[25]), "b" );
    }
    /// Test decryption with keyphrases that includes non-alphabetic characters.
    /// Keyphrase 26 = Illegal characters only
    /// Keyphrase 27 = Illegal characters with lowercase alphabetic characters
    /// Keyphrase 28 = Illegal characters with uppercase alphabetic characters
    /// Keyphrase 29 = Illegal characters with mixedcase alphabetic characters
    void testKeyphraseWithIllegalChars(void)
    {
        TS_FAIL( "Test not implemented" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[26]), "foo" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[27]), "enn" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[28]), "foo" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[29]), "enn" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[26]), "bar" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[27]), "azq" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[28]), "bar" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[29]), "azq" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[26]), "smu" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[27]), "rlt" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[28]), "smu" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[29]), "rlt" );
    }
    /// Test decryption with keyphrases that includes lowercase characters only
    void testKeyphraseWithLowercaseChars(void)
    {
        TS_FAIL( "Test not implemented" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[0]), "foo" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[1]), "enn" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[24]), "foo" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[25]), "enn" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[0]), "bar" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[1]), "azq" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[24]), "bar" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[26]), "azq" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[0]), "smu" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[1]), "rlt" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[24]), "smu" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[26]), "rlt" );
    }
    /// Test decryption with a keyphrase that includes uppercase characters only
    void testKeyphraseWithUppercaseChars(void)
    {
        TS_FAIL( "Test not implemented" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[38]), "foo" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[39]), "enn" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[40]), "foo" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[41]), "enn" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[38]), "bar" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[39]), "azq" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[40]), "bar" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[41]), "azq" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[38]), "smu" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[39]), "rlt" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[40]), "smu" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[41]), "rlt" );
    }
    /// Test decryption with a keyphrase that includes mixedcase characters
    void testKeyphraseWithMixedcaseChars(void)
    {
        TS_FAIL( "Test not implemented" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[34]), "foo" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[35]), "enn" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[36]), "foo" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[37]), "enn" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[34]), "bar" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[35]), "azq" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[36]), "bar" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[37]), "azq" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[34]), "smu" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[35]), "rlt" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[36]), "smu" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[37]), "rlt" );
    }
    /// Test a string containing all the letters of the alphabet
    void testTheQuickBrownFox(void)
    {
        TS_FAIL( "Test not implemented" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[0]), "rfc osgai zpmul dmv hsknq mtcp rfc jyxw bme" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[1]), "sgd pthbj aqnvm enw itlor nudq sgd kzyx cnf" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[2]), "rfc osgai zpmul dmv hsknq mtcp rfc jyxw bme" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[3]), "qeb nrfzh yoltk clu grjmp lsbo qeb ixwv ald" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[4]), "sgd pthbj aqnvm enw itlor nudq sgd kzyx cnf" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[5]), "rfc osgai zpmul dmv hsknq mtcp rfc jyxw bme" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[6]), "qeb nrfzh yoltk clu grjmp lsbo qeb ixwv ald" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[7]), "sgd pthbj aqnvm enw itlor nudq sgd kzyx cnf" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[8]), "rfc osgai zpmul dmv hsknq mtcp rfc jyxw bme" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[9]), "qeb nrfzh yoltk clu grjmp lsbo qeb ixwv ald" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[10]), "sgd pthbj aqnvm enw itlor nudq sgd kzyx cnf" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[11]), "rfc osgai zpmul dmv hsknq mtcp rfc jyxw bme" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[12]), "qeb nrfzh yoltk clu grjmp lsbo qeb ixwv ald" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[13]), "sgd pthbj aqnvm enw itlor nudq sgd kzyx cnf" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[14]), "rfc osgai zpmul dmv hsknq mtcp rfc jyxw bme" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[15]), "qeb nrfzh yoltk clu grjmp lsbo qeb ixwv ald" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[16]), "sgd pthbj aqnvm enw itlor nudq sgd kzyx cnf" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[17]), "rfc osgai zpmul dmv hsknq mtcp rfc jyxw bme" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[18]), "qeb nrfzh yoltk clu grjmp lsbo qeb ixwv ald" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[19]), "sgd pthbj aqnvm enw itlor nudq sgd kzyx cnf" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[20]), "rfc osgai zpmul dmv hsknq mtcp rfc jyxw bme" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[21]), "qeb nrfzh yoltk clu grjmp lsbo qeb ixwv ald" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[22]), "sgd pthbj aqnvm enw itlor nudq sgd kzyx cnf" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[23]), "rfc osgai zpmul dmv hsknq mtcp rfc jyxw bme" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[24]), "qeb nrfzh yoltk clu grjmp lsbo qeb ixwv ald" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[25]), "sgd pthbj aqnvm enw itlor nudq sgd kzyx cnf" );
    }
    /// Test decrypting with an empty keyphrase
    void testEmptyKeyphrase(void)
    {
        TS_ASSERT_EQUALS( substitution_decrypt( "", ""), "" );
        TS_ASSERT_EQUALS( substitution_decrypt( "A", ""), "a" );
        TS_ASSERT_EQUALS( substitution_decrypt( "a", ""), "a" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", ""), "foo" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", ""), "bar" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", ""), "smu" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", ""), "the quick brown fox jumps over the lazy dog" );
    }

private:
    std::vector<std::string> m_keyphrases;
};
