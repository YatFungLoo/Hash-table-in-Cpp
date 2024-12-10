#include "hash.hpp"

void HashTable::insertNode(int value) {
    auto myNode = std::make_unique<HashNode>(value);
    myNode->setKey(templateHashFunction(myNode));
    node_list[0] = *myNode;
    node_count++;
}

std::size_t HashTable::templateHashFunction(std::unique_ptr<HashNode> & node) {
    auto hash = node->getValue() % table_size;
    return hash;
}

void HashTable::templatePrint(std::size_t id) {
    std::cout << "Key " << node_list[id].getKey() << std::endl;
    std::cout << "Value: " << node_list[id].getValue() << std::endl;
}
