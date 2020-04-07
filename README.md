# Secure Hash Algorithm - 256 (sha256)
Lecturer: **Dr Ian McLoughin**   
Module: **Theory of Algorithms**
 

The [Secure Hash Standard (SHS)](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf) was created for computing a condensed representation of electronic data. When a message with length less than 2<sup>64</sup> bits (sha-256) is passed into the algorithm what is produced is a hash value known as the message digest. Any small change(s) made to the input message will with a high probability result in a diffrent message digest being produced. This algorithm is commonly used along side a digitl-signature algorithm which would result in a failure if any change was made to the message.
