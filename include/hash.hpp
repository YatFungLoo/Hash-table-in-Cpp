#include <cstddef>
#include <iostream>
#include <memory>
#include <ostream>

// Single hash node struct.
class HashNode {
  public:
    HashNode(){};
    HashNode(int Value) : value(Value){};
    std::size_t getKey() const { return b_index; }
    void setKey(std::size_t target) {
        b_index = target;
        return;
    }
    int getValue() const { return value; }
    void setValue(int target) {
        value = target;
        return;
    }
    bool isItInitialised() { return init; }
    void toggleInit() {
        init = !init;
        return;
    }
    std::unique_ptr<HashNode> &getNext() { return next; }
    void setNext(std::unique_ptr<HashNode> &node) {
        next = std::move(node);
        return;
    }

  private:
    std::size_t b_index = 0;
    int value = 0;
    std::unique_ptr<HashNode> next = nullptr; // Separate chaining.
    bool init = false;
};

// Class with basic get set function.
class HashTable {
  public:
    // std::unique_ptr<HashNode[]> node_list; // Base node address.
    std::unique_ptr<std::unique_ptr<HashNode>[]> node_list;
    HashTable(size_t size) : table_size(size) {

        // node_list = std::make_unique<HashNode[]>(table_size);
        node_list = std::unique_ptr<std::unique_ptr<HashNode>[]>(new std::unique_ptr<HashNode>[table_size]);
    }

    // std::size_t operator()(const int &b_index) const { return b_index % table_size; }
    // size_t hashFunc(std::unique_ptr<HashNode> &node);
    void insert(const int value);
    void insert(const int value, const int hash, std::unique_ptr<HashNode> &node);
    void search(const int key);

  private:
    int node_count = 0; // Number of elements.
    int table_size = 0; // Size of hash table.

    int hashFunc(const int value);
    bool linearSearch(std::unique_ptr<HashNode> &node, const int key);
    void printRawIndex(size_t id);
};
