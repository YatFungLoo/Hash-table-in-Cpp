#include "hash.hpp"
#include <cassert>

int main() {
    HashTable table(15);
    table.insertNode(16);
    table.templatePrint(0);
    return 0;
}
