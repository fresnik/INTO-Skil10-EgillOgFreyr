INTO-Skil10-EgillOgFreyr
========================

Assignment 10. ENCRYPTION - INTO

Authors:
* Freyr Bergsteinsson <freyrb12@ru.is>
* Egill Bjornsson <egillb12@ru.is>

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/3.0/deed.en_US"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by-nc-sa/3.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/3.0/deed.en_US">Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License</a>.

This project contains two programs that uses known encryption algorithms. One program is called ceasarcipher - it lets let user encrypt and decrypt messages using a [Ceasar cipher](http://en.wikipedia.org/wiki/Caesar_cipher). The other program is called substitutioncipher - it lets the user encrypt and decrypt message using a [subtitution cipher](http://en.wikipedia.org/wiki/Keyword_cipher).

Each program contains a source directory, containing the source code for the program, and a tests directory, containing unit tests for the encryption and decryption algorithms. The unit tests use [CxxTest](http://cxxtest.com/), so be sure to have it installed if you plan on running the unit tests. By default, running make will also generate and run the unit tests. To only compile the programs, run make inside the source code directory for each program.

