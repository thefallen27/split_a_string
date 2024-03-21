# Split a string
This program takes a string and multiple delimiter characters as input, and splits the string based on said delimiters. The function that performs this returns a vector of tokens, which is actually the input broken down into small strings according to the delimiters provided. The program is not affected by multiple occurences of the same delimiter one after the other, or by multiple delimiters that differ between them, as shown in the example below.

## Complexity
The complexity of the provided C++ program that splits a string using multiple characters as delimiters can be analyzed in terms of time and space complexity. This program is optimized for large inputs by allocating memory for the delimiters upfront (using vector::reserve()), and does not create substrings per token (which requires additional memory allocation); instead a vector of positions is created instead.

### Time Complexity
The primary operation in the program is the while loop that searches for delimiters in the input string and extracts tokens based on their positions. This operation is performed by the std::string::find_first_of method, which, in the worst case, can be considered to have a linear time complexity, *O(n)*, with respect to the length of the input string, because it might need to examine each character of the string to find a match with any of the delimiters.

The loop iterates over the entire length of the input string once, performing a linear search at each step to find the next delimiter. The worst-case scenario for time complexity occurs when the delimiters are spread out, causing the method to scan large portions of the input string repeatedly.

Thus, if the length of the input string is *n* and the number of tokens is *k*, the overall worst-case time complexity is *O(n)*. This is because the inner workings of str.find_first_of() function, despite being called multiple times, collectively contribute to a linear scan of the string due to the nature of the string being processed sequentially in its entirety.

### Space Complexity
The space complexity is now primarily determined by the storage of token positions rather than the tokens themselves. For *k* tokens, the space needed is *O(k)* for the vector of TokenPosition structs, each of which requires a constant amount of space (since each TokenPosition consists of two size_t values representing the start and end positions). And while the original string remains in memory, since it is not part of the incremental memory usage attributed to the splitting operation (it would exist in memory regardless of the splitting), it is not counted in the additional space complexity of the SplitString function itself.

However, it is important to consider that strings in C++ may have a short string optimization (SSO), which can affect the actual memory usage for short strings. Here we ignore this optimization for simplicity and assume that the average token length is significantly smaller than the input string length, thus the primary space consideration remains the storage of the positions of the tokens.

## Example
```
Enter the string: Loremipsum-dolor+sit amet,consecteturadipiscing elit-sed-do eiusmod tempor incididunt+ut+labore et dolore/magna aliqua.Ut-enim  ad//minim-+ veniam, quis.
Enter the delimiter characters: +, /.-
Loremipsum
dolor
sit
amet
consecteturadipiscing
elit
sed
do
eiusmod
tempor
incididunt
ut
labore
et
dolore
magna
aliqua
Ut
enim
ad
minim
veniam
quis
```

## License
This project is licensed under the MIT license.
