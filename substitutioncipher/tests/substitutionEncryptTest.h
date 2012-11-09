#include <cxxtest/TestSuite.h>
#include "substitution_encrypt.h"

/**
 * \brief Do various test on the substitution_encrypt() function
 */
class substitutionEncryptTest : public CxxTest::TestSuite
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
    /// Test encryption on a en empty string using different keyphrases
    void testEmptyString(void)
    {
        // No matter what the keyphrase, the output should always be an empty string
        // Test for all known keyphrases
        for ( unsigned int i = 0; i < m_keyphrases.size(); i++ )
        {
            TS_ASSERT_EQUALS( substitution_encrypt( "", m_keyphrases[i]), "" );
        }
    }
    /// Test encryption on all single character strings with the same keyphrase
    void testSingleCharPlaintextWithSameKeyphrase(void)
    {
        TS_ASSERT_EQUALS( substitution_encrypt( "a", m_keyphrases[25]), "T" );
        TS_ASSERT_EQUALS( substitution_encrypt( "b", m_keyphrases[25]), "H" );
        TS_ASSERT_EQUALS( substitution_encrypt( "c", m_keyphrases[25]), "E" );
        TS_ASSERT_EQUALS( substitution_encrypt( "d", m_keyphrases[25]), "Q" );
        TS_ASSERT_EQUALS( substitution_encrypt( "e", m_keyphrases[25]), "U" );
        TS_ASSERT_EQUALS( substitution_encrypt( "f", m_keyphrases[25]), "I" );
        TS_ASSERT_EQUALS( substitution_encrypt( "g", m_keyphrases[25]), "C" );
        TS_ASSERT_EQUALS( substitution_encrypt( "h", m_keyphrases[25]), "K" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[25]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "j", m_keyphrases[25]), "R" );
        TS_ASSERT_EQUALS( substitution_encrypt( "k", m_keyphrases[25]), "O" );
        TS_ASSERT_EQUALS( substitution_encrypt( "l", m_keyphrases[25]), "W" );
        TS_ASSERT_EQUALS( substitution_encrypt( "m", m_keyphrases[25]), "N" );
        TS_ASSERT_EQUALS( substitution_encrypt( "n", m_keyphrases[25]), "F" );
        TS_ASSERT_EQUALS( substitution_encrypt( "o", m_keyphrases[25]), "X" );
        TS_ASSERT_EQUALS( substitution_encrypt( "p", m_keyphrases[25]), "J" );
        TS_ASSERT_EQUALS( substitution_encrypt( "q", m_keyphrases[25]), "M" );
        TS_ASSERT_EQUALS( substitution_encrypt( "r", m_keyphrases[25]), "P" );
        TS_ASSERT_EQUALS( substitution_encrypt( "s", m_keyphrases[25]), "S" );
        TS_ASSERT_EQUALS( substitution_encrypt( "t", m_keyphrases[25]), "V" );
        TS_ASSERT_EQUALS( substitution_encrypt( "u", m_keyphrases[25]), "L" );
        TS_ASSERT_EQUALS( substitution_encrypt( "v", m_keyphrases[25]), "A" );
        TS_ASSERT_EQUALS( substitution_encrypt( "w", m_keyphrases[25]), "Z" );
        TS_ASSERT_EQUALS( substitution_encrypt( "x", m_keyphrases[25]), "Y" );
        TS_ASSERT_EQUALS( substitution_encrypt( "y", m_keyphrases[25]), "D" );
        TS_ASSERT_EQUALS( substitution_encrypt( "z", m_keyphrases[25]), "G" );
    }
    /// Test encryption on a single character using various keyphrases
    void testSingleCharPlaintext(void)
    {
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[0]), "H" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[1]), "G" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[2]), "G" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[3]), "F" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[4]), "D" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[5]), "C" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[6]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[7]), "A" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[8]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[9]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[10]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[11]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[12]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[13]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[14]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[15]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[16]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[17]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[18]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[19]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[20]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[21]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[22]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[23]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[24]), "B" );
        TS_ASSERT_EQUALS( substitution_encrypt( "i", m_keyphrases[25]), "B" );
    }
    /// Test encryption with keyphrases that includes non-alphabetic characters.
    /// Keyphrase 26 = Illegal characters only
    /// Keyphrase 27 = Illegal characters with lowercase alphabetic characters
    /// Keyphrase 28 = Illegal characters with uppercase alphabetic characters
    /// Keyphrase 29 = Illegal characters with mixedcase alphabetic characters
    void testKeyphraseWithIllegalChars(void)
    {
        TS_ASSERT_EQUALS( substitution_encrypt( "foo", m_keyphrases[26]), "FOO" );
        TS_ASSERT_EQUALS( substitution_encrypt( "foo", m_keyphrases[27]), "ZLL" );
        TS_ASSERT_EQUALS( substitution_encrypt( "foo", m_keyphrases[28]), "WLL" );
        TS_ASSERT_EQUALS( substitution_encrypt( "foo", m_keyphrases[29]), "TLL" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bar", m_keyphrases[26]), "BAR" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bar", m_keyphrases[27]), "BAO" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bar", m_keyphrases[28]), "EDO" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bar", m_keyphrases[29]), "HGO" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smu", m_keyphrases[26]), "SMU" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smu", m_keyphrases[27]), "PJR" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smu", m_keyphrases[28]), "PJR" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smu", m_keyphrases[29]), "PJU" );
    }
    /// Test encryption with keyphrases that includes lowercase characters only
    void testKeyphraseWithLowercaseChars(void)
    {
        TS_ASSERT_EQUALS( substitution_encrypt( "foo", m_keyphrases[0]), "ENN" );
        TS_ASSERT_EQUALS( substitution_encrypt( "foo", m_keyphrases[1]), "DNN" );
        TS_ASSERT_EQUALS( substitution_encrypt( "foo", m_keyphrases[24]), "IXX" );
        TS_ASSERT_EQUALS( substitution_encrypt( "foo", m_keyphrases[25]), "IXX" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bar", m_keyphrases[0]), "ATQ" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bar", m_keyphrases[1]), "HTQ" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bar", m_keyphrases[24]), "HTP" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bar", m_keyphrases[25]), "HTP" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smu", m_keyphrases[0]), "RLU" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smu", m_keyphrases[1]), "RLU" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smu", m_keyphrases[24]), "SNL" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smu", m_keyphrases[25]), "SNL" );
    }
    /// Test encryption with a keyphrase that includes uppercase characters only
    void testKeyphraseWithUppercaseChars(void)
    {
        TS_ASSERT_EQUALS( substitution_encrypt( "foo", m_keyphrases[30]), "ENN" );
        TS_ASSERT_EQUALS( substitution_encrypt( "foo", m_keyphrases[31]), "DNN" );
        TS_ASSERT_EQUALS( substitution_encrypt( "foo", m_keyphrases[32]), "IXX" );
        TS_ASSERT_EQUALS( substitution_encrypt( "foo", m_keyphrases[33]), "IXX" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bar", m_keyphrases[30]), "ATQ" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bar", m_keyphrases[31]), "HTQ" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bar", m_keyphrases[32]), "HTP" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bar", m_keyphrases[33]), "HTP" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smu", m_keyphrases[30]), "RLU" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smu", m_keyphrases[31]), "RLU" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smu", m_keyphrases[32]), "SNL" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smu", m_keyphrases[33]), "SNL" );
    }
    /// Test encryption with a keyphrase that includes mixedcase characters
    void testKeyphraseWithMixedcaseChars(void)
    {
        TS_ASSERT_EQUALS( substitution_encrypt( "foo", m_keyphrases[34]), "ILL" );
        TS_ASSERT_EQUALS( substitution_encrypt( "foo", m_keyphrases[35]), "IXX" );
        TS_ASSERT_EQUALS( substitution_encrypt( "foo", m_keyphrases[36]), "IXX" );
        TS_ASSERT_EQUALS( substitution_encrypt( "foo", m_keyphrases[37]), "IXX" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bar", m_keyphrases[34]), "HTO" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bar", m_keyphrases[35]), "HTG" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bar", m_keyphrases[36]), "HTP" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bar", m_keyphrases[37]), "HTP" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smu", m_keyphrases[34]), "PGS" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smu", m_keyphrases[35]), "JNM" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smu", m_keyphrases[36]), "SNA" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smu", m_keyphrases[37]), "SNL" );
    }
    /// Test encyption of plaintext containing uppercase characters
    void testPlaintextWithUppercaseChars(void)
    {
        TS_ASSERT_EQUALS( substitution_encrypt( "FOO", m_keyphrases[0]), "ENN" );
        TS_ASSERT_EQUALS( substitution_encrypt( "fOO", m_keyphrases[1]), "DNN" );
        TS_ASSERT_EQUALS( substitution_encrypt( "foO", m_keyphrases[24]), "IXX" );
        TS_ASSERT_EQUALS( substitution_encrypt( "Foo", m_keyphrases[25]), "IXX" );
        TS_ASSERT_EQUALS( substitution_encrypt( "BAR", m_keyphrases[0]), "ATQ" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bAR", m_keyphrases[1]), "HTQ" );
        TS_ASSERT_EQUALS( substitution_encrypt( "baR", m_keyphrases[24]), "HTP" );
        TS_ASSERT_EQUALS( substitution_encrypt( "Bar", m_keyphrases[25]), "HTP" );
        TS_ASSERT_EQUALS( substitution_encrypt( "SMU", m_keyphrases[0]), "RLU" );
        TS_ASSERT_EQUALS( substitution_encrypt( "sMU", m_keyphrases[1]), "RLU" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smU", m_keyphrases[24]), "SNL" );
        TS_ASSERT_EQUALS( substitution_encrypt( "Smu", m_keyphrases[25]), "SNL" );
    }
    /// Test a string containing all the letters of the alphabet
    void testTheQuickBrownFox(void)
    {
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[0]), "SGD PUHBJ AQNWM ENX IULOR NVDQ SGD KTZY CNF" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[1]), "SFC PUGAJ HQNWM DNX IULOR NVCQ SFC KTZY BNE" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[2]), "SFB PUGEJ HQNWM CNX IULOR NVBQ SFB KTZY AND" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[3]), "SDA OUFEI HPMWL BMX GUKNR MVAP SDA JTZY QMC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[4]), "RCU NSDEG HOLWK ALX FSJMP LVUO RCU ITZY QLB" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[5]), "RBU NSCEF HOLWK ILX DSJMP LVUO RBU GTZY QLA" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[6]), "RAU NSBEF HOLWK ILX DSJMP LVUO RAU GTZY QLC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[7]), "RKU NSAED HOLWJ ILX BSGMP LVUO RKU FTZY QLC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[8]), "RKU NSBED HOLWJ ILX ASGMP LVUO RKU FTZY QLC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[9]), "PKU MSBEA HNJWG IJX RSFLO JVUN PKU DTZY QJC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[10]), "PKU LSBEO HMGWF IGX RSDJN GVUM PKU ATZY QGC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[11]), "NKU JPBEO HLFVD IFX RPAGM FSUL NKU WTZY QFC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[12]), "MKU GPBEO HJDVA IDX RPNFL DSUJ MKU WTZY QDC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[13]), "MKU GPBEO HJAVF IAX RPNDL ASUJ MKU WTZY QAC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[14]), "LKU DMBEO HGXSF IXV RMNAJ XPUG LKU WTZY QXC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[15]), "LKU AMBEO HDXSF IXV RMNJG XPUD LKU WTZY QXC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[16]), "GKU MLBEO HAXSF IXV RLNJD XPUA GKU WTZY QXC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[17]), "DKU MGBEO HPXSF IXV RGNJA XLUP DKU WTZY QXC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[18]), "AKU MDBEO HPXLF IXV RDNJS XGUP AKU WTZY QXC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[19]), "VKU MABEO HPXGF IXL RANJS XDUP VKU WTZY QXC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[20]), "VKU MLBEO HPXDF IXG RLNJS XAUP VKU WTZY QXC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[21]), "VKU MLBEO HPXDF IXG RLNJS XAUP VKU WTZY QXC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[22]), "VKU MLBEO HPXZF IXD RLNJS XAUP VKU WTYG QXC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[23]), "VKU MLBEO HPXZF IXY RLNJS XAUP VKU WTGD QXC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[24]), "VKU MLBEO HPXZF IXY RLNJS XAUP VKU WTGD QXC" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", m_keyphrases[25]), "VKU MLBEO HPXZF IXY RLNJS XAUP VKU WTGD QXC" );
    }
    /// Test encrypting with an empty keyphrase
    void testEmptyKeyphrase(void)
    {
        TS_ASSERT_EQUALS( substitution_encrypt( "", ""), "" );
        TS_ASSERT_EQUALS( substitution_encrypt( "A", ""), "A" );
        TS_ASSERT_EQUALS( substitution_encrypt( "a", ""), "A" );
        TS_ASSERT_EQUALS( substitution_encrypt( "foo", ""), "FOO" );
        TS_ASSERT_EQUALS( substitution_encrypt( "bar", ""), "BAR" );
        TS_ASSERT_EQUALS( substitution_encrypt( "smu", ""), "SMU" );
        TS_ASSERT_EQUALS( substitution_encrypt( "the quick brown fox jumps over the lazy dog", ""), "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG" );
    }
 private:
    std::vector<std::string> m_keyphrases;
};
