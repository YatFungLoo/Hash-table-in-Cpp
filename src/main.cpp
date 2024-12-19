#include "hash.hpp"
#include <cassert>

int main() {
    HashTable table(15);
    table.insert(20);
    table.search(20);
    table.insert(5);
    table.search(5);
    return 0;
}
