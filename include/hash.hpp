#include <cstddef>
#include <iostream>

// Single hash node struct.
struct HashNode {
    int b_index = 0;
    int value = 0;
    // Separate chaining.
    HashNode *next = nullptr;
};

// Class with basic get set function.
class HashTable {
  public:
    HashTable(const int &size) : table_size(size) {
        node_list = (HashNode **)malloc(sizeof(HashNode *) * this->table_size);
        HashNode *myNode = new HashNode;
        myNode->value = 10;
        HashNode *myNode1 = new HashNode;
        myNode1->value = 15;
        node_list[0] = myNode;
        node_list[1] = myNode1;
    }
    std::size_t operator()(const int &b_index) const { return b_index % table_size; }
    int getKey() const { return 0; }
    int getValue() const { return 0; }
    void setValue() { return; }
    void setNext() { return; }
    size_t templateHashFunction();

  private:
    HashNode **node_list; // Base node address.
    int node_count = 0;   // Number of elements.
    int table_size = 0;   // Size of hash table.
};
