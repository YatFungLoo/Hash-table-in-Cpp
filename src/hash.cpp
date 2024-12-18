#include "hash.hpp"

// std::size_t HashTable::hashFunc(std::unique_ptr<HashNode> & node) {
int HashTable::hashFunc(const int value) {
    auto hash = value % table_size;
    return hash;
}

void HashTable::insert(const int value) {
    auto hash = hashFunc(value);
    auto my_node = std::make_unique<HashNode>(value);
    my_node->setKey(hash);
    my_node->toggleInit();
    // TODO fix
    node_list[hash] = std::move(my_node);
    return;

    if (node_list[hash]->isItInitialised() == true && node_list[hash]->getNext() == nullptr) {
        auto next_node = std::make_unique<HashNode>(value);
        node_list[hash]->setNext(next_node);
        insert(value, hash, next_node);
        return;
    }

    if (node_list[hash]->isItInitialised() == false) {
        auto my_node = std::make_unique<HashNode>(value);
        my_node->setKey(hash);
        my_node->toggleInit();
        // TODO fix
        node_list[hash] = std::move(my_node);
    }

    node_count++;
    return;
}

// Simple linked list insert.
void HashTable::insert(const int value, const int hash, std::unique_ptr<HashNode> &node) {
    if (node->isItInitialised() == true) {
        insert(value, hash, node->getNext());
        return;
    }

    if (node->isItInitialised() == false) {
        auto myNode = std::make_unique<HashNode>(value);
        myNode->setKey(hash);
        myNode->toggleInit();
        node = std::move(myNode);
    }

    node_count++;
    return;
}

void HashTable::search(const int key) {
    auto b_index = hashFunc(key);
    auto &target_node = node_list[b_index];

    if (target_node->isItInitialised() == false) {
        std::cout << "Key not found:" << std::endl;
        return;
    }

    bool hit = linearSearch(target_node, key);

    if (hit == true) {
        std::cout << "Key found:" << std::endl;
        printRawIndex(b_index);
        return;
    } else if (hit == false) {
        std::cout << "Key not found:" << std::endl;
    }
}

bool HashTable::linearSearch(std::unique_ptr<HashNode> &node, const int key) {
    auto value = node->getValue();

    // Hit at linked list head.
    if (value == key) {
        return true;
    }

    // Iterate until nullptr hit.
    auto &next_node = node->getNext();
    while (next_node != nullptr) {
        value = next_node->getValue();
        if (value == key) {
            return true;
        }
        next_node = std::move(next_node->getNext());
    }

    return false;
}

void HashTable::printRawIndex(std::size_t id) {
    std::cout << "Key " << node_list[id]->getKey() << std::endl;
    std::cout << "Value: " << node_list[id]->getValue() << std::endl;
    std::cout << "Node counts: " << node_count << std::endl;
}
