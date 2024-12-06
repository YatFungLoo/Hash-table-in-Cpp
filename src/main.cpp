#include "hash.hpp"
#include <cassert>
#include <ostream>

int main() {
    HashTable table(15);
    table.templatePrint();
    std::cout << "Hash: " << table.templateHashFunction() << std::endl;
    auto node_list = std::unique_ptr<HashNode[]>(new HashNode[10]);
    return 0;
}
