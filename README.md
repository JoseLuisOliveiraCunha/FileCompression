# FileCompression

##### A project developed to implement Huffman coding and test it as a standalone file compression method as well.

## Current version features:
+ Works with any file in any directory
+ Successfully calculates the Huffman tree and Huffman codes for each different token present in the file (byte)
+ Outputs the compressed data to a file in the original directory with the same name as the original file but with a .compressed extension

## Future features:
+ Output file header with the data from the Huffman tree to allow file decompression
+ Handle exceptions
+ Allow file decompression
+ Make compression/decompression multi-threaded to improve performance
+ Tweak code to improve performance
+ Improve the console UI and give more feedback to the user about the operation progress
