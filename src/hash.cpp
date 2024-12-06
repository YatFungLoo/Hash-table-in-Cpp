#include "hash.hpp"
size_t HashTable::templateHashFunction() { return node_list[0].getValue() % table_size; }
void HashTable::templatePrint() {
    // std::cout << "Key" << node_list[0].getKey() << std::endl;
    std::cout << "Value: " << node_list[0].getValue() << std::endl;
}
