#include <cxxtest/TestSuite.h>
#include "substitution_decrypt.h"

/**
 * \brief Do various test on the substitution_decrypt() function
 */
class substitutionDecryptTest : public CxxTest::TestSuite
{
public:
    void setUp(void)
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
        m_keyphrases.push_back( " ,.!\"#$%&/()=_-'+?*:;DEFUVWáéýúíóþæðöÁÉÝÚÍÓÞÆÐÖ" );
        m_keyphrases.push_back( " ,.!\"#$%&/()=_-'+?*:;GHIrstáéýúíóþæðöÁÉÝÚÍÓÞÆÐÖ" );
        m_keyphrases.push_back( "T" );
        m_keyphrases.push_back( "TH" );
        m_keyphrases.push_back( "THE QUICK BROWN FOX JUMPS OVER THE LAZY D" );
        m_keyphrases.push_back( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG" );
        m_keyphrases.push_back( "THE quick" );
        m_keyphrases.push_back( "THE QUICK brown fox" );
        m_keyphrases.push_back( "THE QUICK BROWN fox jumps over" );
        m_keyphrases.push_back( "THE QUICK BROWN FOX jumps over the lazy" );
     }
     void tearDown()
     {
        m_keyphrases.clear();
     }
    /// Test decryption on a en empty string using different keyphrases
    void testEmptyString(void)
    {
        // No matter what the keyphrase, the output should always be an empty string
        // Test for all known keyphrases
        for ( unsigned int i = 0; i < m_keyphrases.size(); i++ )
        {
            TS_ASSERT_EQUALS( substitution_decrypt( "", m_keyphrases[i]), "" );
        }
    }
	/// Test decryption on all single character strings with the same keyphrase
    void testSingleCharEncryptedTextsWithSameKeyphrase(void)
    {
        TS_ASSERT_EQUALS( substitution_decrypt( "A", m_keyphrases[25]), "v" );
        TS_ASSERT_EQUALS( substitution_decrypt( "B", m_keyphrases[25]), "i" );
        TS_ASSERT_EQUALS( substitution_decrypt( "C", m_keyphrases[25]), "g" );
        TS_ASSERT_EQUALS( substitution_decrypt( "D", m_keyphrases[25]), "y" );
        TS_ASSERT_EQUALS( substitution_decrypt( "E", m_keyphrases[25]), "c" );
        TS_ASSERT_EQUALS( substitution_decrypt( "F", m_keyphrases[25]), "n" );
        TS_ASSERT_EQUALS( substitution_decrypt( "G", m_keyphrases[25]), "z" );
        TS_ASSERT_EQUALS( substitution_decrypt( "H", m_keyphrases[25]), "b" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[25]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "J", m_keyphrases[25]), "p" );
        TS_ASSERT_EQUALS( substitution_decrypt( "K", m_keyphrases[25]), "h" );
        TS_ASSERT_EQUALS( substitution_decrypt( "L", m_keyphrases[25]), "u" );
        TS_ASSERT_EQUALS( substitution_decrypt( "M", m_keyphrases[25]), "q" );
        TS_ASSERT_EQUALS( substitution_decrypt( "N", m_keyphrases[25]), "m" );
        TS_ASSERT_EQUALS( substitution_decrypt( "O", m_keyphrases[25]), "k" );
        TS_ASSERT_EQUALS( substitution_decrypt( "P", m_keyphrases[25]), "r" );
        TS_ASSERT_EQUALS( substitution_decrypt( "Q", m_keyphrases[25]), "d" );
        TS_ASSERT_EQUALS( substitution_decrypt( "R", m_keyphrases[25]), "j" );
        TS_ASSERT_EQUALS( substitution_decrypt( "S", m_keyphrases[25]), "s" );
        TS_ASSERT_EQUALS( substitution_decrypt( "T", m_keyphrases[25]), "a" );
        TS_ASSERT_EQUALS( substitution_decrypt( "U", m_keyphrases[25]), "e" );
        TS_ASSERT_EQUALS( substitution_decrypt( "V", m_keyphrases[25]), "t" );
        TS_ASSERT_EQUALS( substitution_decrypt( "W", m_keyphrases[25]), "l" );
        TS_ASSERT_EQUALS( substitution_decrypt( "X", m_keyphrases[25]), "o" );
        TS_ASSERT_EQUALS( substitution_decrypt( "Y", m_keyphrases[25]), "x" );
        TS_ASSERT_EQUALS( substitution_decrypt( "Z", m_keyphrases[25]), "w" );
    }
    /// Test decryption on a single character using various keyphrases
    void testSingleCharEncryptedText(void)
    {
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[0]), "j" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[1]), "j" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[2]), "j" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[3]), "k" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[4]), "l" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[5]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[6]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[7]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[8]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[9]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[10]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[11]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[12]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[13]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[14]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[15]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[16]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[17]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[18]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[19]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[20]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[21]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[22]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[23]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[24]), "f" );
        TS_ASSERT_EQUALS( substitution_decrypt( "I", m_keyphrases[25]), "f" );
    }
    /// Test decryption with keyphrases that includes non-alphabetic characters.
    /// Keyphrase 26 = Illegal characters only
    /// Keyphrase 27 = Illegal characters with lowercase alphabetic characters
    /// Keyphrase 28 = Illegal characters with uppercase alphabetic characters
    /// Keyphrase 29 = Illegal characters with mixedcase alphabetic characters
    void testKeyphraseWithIllegalChars(void)
    {
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[26]), "foo" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[27]), "irr" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[28]), "crr" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[29]), "lrr" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[26]), "bar" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[27]), "bau" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[28]), "hgu" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[29]), "hgd" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[26]), "smu" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[27]), "vpx" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[28]), "vpd" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[29]), "epu" );
    }
    /// Test decryption with keyphrases that includes lowercase characters only
    void testKeyphraseWithLowercaseChars(void)
    {
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[0]), "gpp" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[1]), "hpp" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[24]), "nkk" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[25]), "nkk" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[0]), "cbs" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[1]), "dcs" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[24]), "ivj" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[25]), "ivj" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[0]), "tnu" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[1]), "tnu" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[24]), "sqe" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[25]), "sqe" );
    }
    /// Test decryption with a keyphrase that includes uppercase characters only
    void testKeyphraseWithUppercaseChars(void)
    {
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[30]), "gpp" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[31]), "hpp" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[32]), "nkk" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[33]), "nkk" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[30]), "cbs" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[31]), "dcs" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[32]), "ivj" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[33]), "ivj" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[30]), "tnu" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[31]), "tnu" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[32]), "sqe" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[33]), "sqe" );
    }
    /// Test decryption with a keyphrase that includes mixedcase characters
    void testKeyphraseWithMixedcaseChars(void)
    {
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[34]), "lrr" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[35]), "nkk" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[36]), "nkk" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOO", m_keyphrases[37]), "nkk" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[34]), "jit" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[35]), "ipj" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[36]), "iuj" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAR", m_keyphrases[37]), "ivj" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[34]), "upe" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[35]), "wue" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[36]), "sqe" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMU", m_keyphrases[37]), "sqe" );
    }
    /// Test decyption of encrypted text containing lowercase characters
    void testEncryptedTextWithLowercaseChars(void)
    {
        TS_ASSERT_EQUALS( substitution_decrypt( "foo", m_keyphrases[0]), "gpp" );
        TS_ASSERT_EQUALS( substitution_decrypt( "Foo", m_keyphrases[1]), "hpp" );
        TS_ASSERT_EQUALS( substitution_decrypt( "FOo", m_keyphrases[24]), "nkk" );
        TS_ASSERT_EQUALS( substitution_decrypt( "fOO", m_keyphrases[25]), "nkk" );
        TS_ASSERT_EQUALS( substitution_decrypt( "bar", m_keyphrases[0]), "cbs" );
        TS_ASSERT_EQUALS( substitution_decrypt( "Bar", m_keyphrases[1]), "dcs" );
        TS_ASSERT_EQUALS( substitution_decrypt( "BAr", m_keyphrases[24]), "ivj" );
        TS_ASSERT_EQUALS( substitution_decrypt( "bAR", m_keyphrases[25]), "ivj" );
        TS_ASSERT_EQUALS( substitution_decrypt( "smu", m_keyphrases[0]), "tnu" );
        TS_ASSERT_EQUALS( substitution_decrypt( "Smu", m_keyphrases[1]), "tnu" );
        TS_ASSERT_EQUALS( substitution_decrypt( "SMu", m_keyphrases[24]), "sqe" );
        TS_ASSERT_EQUALS( substitution_decrypt( "sMU", m_keyphrases[25]), "sqe" );
    }
    /// Test a string containing all the letters of the alphabet
    void testTheQuickBrownFox(void)
    {
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[0]), "aif rujdl cspwo gpx kunqt pvfs aif mbzy eph" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[1]), "abg rujel dspwo hpx kunqt pvgs abg mczy fpi" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[2]), "abc rujfl espwo hpx kunqt pvcs abc mdzy gpi" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[3]), "abc dukgm fsqwp iqx luort qvcs abc nezy hqj" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[4]), "abc delhn gtrwq jrx mepsu rvct abc ofzy irk" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[5]), "abc defin htrwq krx mepsu rvct abc ogzy jrl" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[6]), "abc defgn itrwq krx mepsu rvct abc ohzy jrl" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[7]), "abc defgh jtrwq lrx nepsu rvct abc oizy krm" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[8]), "abc defgh itrwq lrx nepsu rvct abc ojzy krm" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[9]), "abc defgh ijswr msx oeqtu svcj abc pkzy lsn" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[10]), "abc defgh ijkws nkx pertu kvcj abc qlzy mko" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[11]), "abc defgh ijklt okx qesuv kwcj abc rmzy nkp" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[12]), "abc defgh ijklm pkx retuv kwcj abc snzy okq" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[13]), "abc defgh ijklm nkx retuv kwcj abc sozy pkq" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[14]), "abc defgh ijklm nko seuvw kxcj abc tpzy qkr" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[15]), "abc defgh ijklm nko peuvw kxcj abc tqzy rks" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[16]), "abc defgh ijklm nko peqvw kxcj abc urzy skt" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[17]), "abc defgh ijklm nko peqrw kxcj abc vszy tku" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[18]), "abc defgh ijklm nko peqrs kxcj abc wtzy ukv" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[19]), "abc defgh ijklm nko peqrs ktcj abc xuzy vkw" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[20]), "abc defgh ijklm nko peqrs ktcj abc uvzy wkx" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[21]), "abc defgh ijklm nko peqrs ktcj abc uvzy wkx" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[22]), "abc defgh ijklm nko peqrs ktcj abc uvwz xky" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[23]), "abc defgh ijklm nko peqrs ktcj abc uvwx ykz" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[24]), "abc defgh ijklm nko peqrs ktcj abc uvwx ykz" );
        TS_ASSERT_EQUALS( substitution_decrypt( "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", m_keyphrases[25]), "abc defgh ijklm nko peqrs ktcj abc uvwx ykz" );
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
