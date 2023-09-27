# xbn
Modified RLE Compression implementation based on algorithms from [this paper](https://dx.doi.org/10.14569/IJACSA.2016.070734).

## Algorithm Description

### RLE Basics

Run-length encoding (RLE) is a simple data compression technique that is used to reduce the size of data by encoding sequences of repeated values into shorter representations. It is particularly effective for data that contains long sequences of the same value.

The basic idea behind run-length encoding is to parse a string of data into value-length pairs, and then encode those pairs into a storable representation by some algorithm.

Consider a string of characters: 

`AAABBBCDDDDE22221`. 

If we symbolically represent a value-length pair as {_v_,_l_} where _v_ is the value and _l_ is the run-length, the above string encodes as 

`{A,3}{B,3}{C,1}{D,4}{E,1}{2,4}{1,1}`

From this symbolic representation, we move on to the more nuanced step of RLE compression, what I will call "storage encoding". The storage encoding has 2 goals:
1. Create a string that can be unambiguously decoded back into the symbolic representation.
2. Reduce the storage requirements of a value, run length pair. This is particularly important for data comprised mostly of short runs.

Taking our symbolic representation verbatim and converting it to ASCII text would be a valid storage encoding that satisfies the first goal. Unfortunately, it falls short on the second goal. Note that in the symbolic representation, each value-length pair requires at least 5 characters to represent. So for data that is mostly made up of runs shorter than 5, this storage encoding would  

This symbolic representation is itself a valid run-length encoding that could be stored verbatim, perhaps as ASCII text. However, that ASCII text would actually exceed the size of the original string. There are some techniques we can apply to reduce its size
