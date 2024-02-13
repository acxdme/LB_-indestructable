// 05 : Trie operations
#include <iostream>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = nullptr;
    }

    void insert(const std::string& word) {
        if (root == nullptr) {
            root = new TrieNode();
        }
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) != current->children.end()) {
                current = current->children[c];
            }
            else{ // fix : else condition added.
               TrieNode* child = new TrieNode();
               current->children[c] = child;
               current = current->children[c];
            }
        }
        current->isEndOfWord = true;
    }

    bool search(const std::string& word) { 
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }
        return current->isEndOfWord;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("carrot");

    std::cout << trie.search("apple") << std::endl;
    std::cout << trie.search("banana") << std::endl;
    std::cout << trie.search("carrot") << std::endl;
    std::cout << trie.search("grape") << std::endl;

    return 0;
}
