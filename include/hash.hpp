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
    void setNext() {
        next = nullptr;
        return;
    }

  private:
    std::size_t b_index = 0;
    int value = 0;
    // Separate chaining.
    HashNode *next = nullptr;
};

// Class with basic get set function.
class HashTable {
  public:
    std::unique_ptr<HashNode[]> node_list; // Base node address.
    HashTable(size_t size) : table_size(size) {
        node_list = std::make_unique<HashNode[]>(table_size);
        // auto myNode = std::make_unique<HashNode>(10);
        // node_list[0] = *myNode;
        // node_count++;
    }
    
    void insertNode(int value);
    // std::size_t operator()(const int &b_index) const { return b_index % table_size; }
    size_t templateHashFunction(std::unique_ptr<HashNode> & node);
    void templatePrint(size_t id);

  private:
    int node_count = 0; // Number of elements.
    int table_size = 0; // Size of hash table.
};
