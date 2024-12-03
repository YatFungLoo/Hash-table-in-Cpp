#include "hash.hpp"
#include <cassert>
#include <stdlib.h>

#define SIZE 10 // temp size of hash table.

int main() {
    HashTable node(15);
    // std::cout << "Key: " << node.getKey() << std::endl;
    std::cout << "Hash: " << std::endl << node.templateHashFunction() << std::endl;
    return 0;
}
