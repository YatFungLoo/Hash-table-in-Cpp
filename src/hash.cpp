#include "hash.hpp"
size_t HashTable::templateHashFunction() {
    std::cout << node_list[0]->value % table_size << std::endl;
    std::cout << node_list[1]->value % table_size << std::endl;
    return 99;
}
