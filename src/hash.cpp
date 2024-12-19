#include "hash.hpp"

// std::size_t HashTable::hashFunc(std::unique_ptr<HashNode> & node) {
int HashTable::hashFunc(const int value) {
    auto hash = value % table_size;
    return hash;
}

void HashTable::insert(const int value) {
    auto hash = hashFunc(value);
    // If node_list[n] is pointing to nullptr, it is empty.
    if (node_list[hash] != nullptr) {
        auto next_node = std::make_unique<HashNode>(value);
        node_list[hash]->setNext(next_node);
        insert(value, hash, next_node);
        return;
    }

    if (node_list[hash] == nullptr) {
        auto my_node = std::make_unique<HashNode>(value);
        my_node->setKey(hash);
        node_list[hash] = std::move(my_node);
        node_count++;
        return;
    }
    return;
}

// Singular linked list.
void HashTable::insert(const int value, const int hash, std::unique_ptr<HashNode> &node) {
    if (node != nullptr) {
        insert(value, hash, node->getNext());
        return;
    }

    if (node == nullptr) {
        auto myNode = std::make_unique<HashNode>(value);
        myNode->setKey(hash);
        node = std::move(myNode);
    }

    node_count++;
    return;
}

void HashTable::search(const int value) {
    auto b_index = hashFunc(value);
    auto &target_node = node_list[b_index];

    if (target_node == nullptr) {
        std::cout << "Key not found:" << std::endl;
        return;
    }

    bool hit = linearSearch(target_node, value);

    if (hit == true) {
        std::cout << "Key found" << std::endl;
        return;
    } else if (hit == false) {
        std::cout << "Key not found" << std::endl;
    }
}

bool HashTable::linearSearch(std::unique_ptr<HashNode> &node, const int value) {
    auto node_value = node->getValue();

    // Hit at linked list head.
    if (node_value == value) {
        return true;
    }

    // Iterate until nullptr hit.
    auto &next_node = node->getNext();
    while (next_node != nullptr) {
        node_value = next_node->getValue();
        if (node_value == value) {
            return true;
        }
        next_node = std::move(next_node->getNext());
    }

    return false;
}

void HashTable::printRawIndex(std::unique_ptr<HashNode> &node) {
    std::cout << "Key " << node->getKey() << std::endl;
    std::cout << "Value: " << node->getValue() << std::endl;
    std::cout << "Node counts: " << node_count << std::endl;
}
