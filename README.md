# Simple hash table implementation in C++
Hash table written in C++. References:

1. Algoritms Forth Edition by Robert Sedgewick.
2. https://aozturk.medium.com/simple-hash-map-hash-table-implementation-in-c-931965904250
3. https://www.geeksforgeeks.org/implementation-of-hash-table-in-c-using-separate-chaining/

<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [Simple hash table implementation in C++](#simple-hash-table-implementation-in-c)
  - [TODO](#todo)
  - [Hasing](#hasing)
  - [Time-space tradeoff](#time-space-tradeoff)
  - [Hash function](#hash-function)
  - [To compiled](#to-compiled)

<!-- markdown-toc end -->

## TODO
1. First implementation -> separate chaining
2. Second implementation -> Open address

## Hasing
*Hash function* that transforms the search key into an array index, ideally different key would map to different indices but keys will hash the same array index.

*Collision-resolution* process deals with hash clashing, two approaches include *separate chaining* and *linear probing*.

## Time-space tradeoff
The reason why hashing is viable. Memory limitation, cannot use key as an index because number of possible key can overflow memory. Time limitation, unordered sequential search can take more time than the life of the universe.

Hashing takes a balance of both.

## Hash function
Each key types required a unique hash function, which the programmer provides. But all are variation of modular hashing, referring to using the reminder of keys divided by the array size which are preferably a prime number to dispersing keys evenly.

| *Keys types*      | *Hashing method example*                            |
|:-----------------:|:---------------------------------------------------:|
| Positive integers | modular hashing with closest prime number.          |
| Float numbers     | modular hashing on binary representations.          |
| String            | cast as int then modular hashing (Horner’s method). |
| Compound keys     | treated same as String.                             |

## To compiled
```
mkdir build && cd build
```

```
cmake .. --preset=debug
```

or 

```
cmake .. --preset=release
```

```
ninja clean && ninja
```

and executable will exist in the `build/` directory.
