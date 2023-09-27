# xbn
Run-length encoding (RLE) is a simple data compression technique that is used to reduce the size of data by encoding sequences of repeated values into shorter representations. It is particularly effective for data that contains long sequences of the same value. Even so, there are parameters and techniques that an RLE implementation can apply to improve its effectiveness for less repetitive data.

This software implements RLE techniques outlined in [this paper](https://dx.doi.org/10.14569/IJACSA.2016.070734). Specifically, it tailors the IXBN and IXBSN type encoders to work with 1-bit signals.

Since the implementation is for a fixed character width (1-bit), it is able to utilize an additional encoding optimization.

Consider the 1-bit signal

`1111100000110000101000000`

and its representation as a sequence of (character, run-length) pairs

`(1,5),(0,5),(1,2),(0,4),(1,1),(0,1),(0,6)`

Note that because there are only 2 possible characters in the signal, we can deduce that a run of 1s _must_ be followed by a run of 0s, and vice versa. If a run of 0s were followed by another run of 0s, then we could just combine them into a single run. Therefore, instead of having to encode character-length pairs in our output stream, we only have to record the sequence of lengths and the initial character. With this observation, the above signal can be represented as

`Initial char: 1 Lengths: 5,5,2,4,1,1,6`

Now we can encode the sequence of lengths with the techniques in the paper.

I1BN encoding:

`1 | 1100 | 1100 | 1000 | 1011 | 0 | 0 | 1101` = 23 bits

I2BN encoding:

`1 | 1110 | 1110 | 10 | 1101 | 0 | 0 | 1111` = 21 bits

I3BN encoding:

`1 | 11101 | 11101 | 10 | 11100 | 0 | 0 | 11110` = 25 bits

I1BSN encoding:

`1 | 11011 | 11011 | 1010 | 11010 | 0 | 0 | 11100` = 27 bits

I2BSN encoding:

`1 | 1101 | 1101 | 10 | 1100 | 0 | 0 | 11100` = 22 bits

