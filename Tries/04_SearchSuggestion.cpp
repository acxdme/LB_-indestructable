// lc- 1268
// tc - O( (l*k)^2)
// sc - O(l * k) , k is no.of products , l is the length of the product

class Solution {
public:
    class TrieNode {
    public:
        char ch;
        TrieNode* children[26];
        bool isTerminal;

        // ctor
        TrieNode(char data) {
            this->ch = data;
            for (int i = 0; i < 26; i++) {
                this->children[i] = NULL;
            }
            this->isTerminal = false;
        }
    };

    void insert(TrieNode* root, string str) {

        // base-case
        if (str.size() == 0) {
            root->isTerminal = true;
            return;
        }

        TrieNode* child = NULL;
        char ch = str[0];

        // if child exists , move to child
        if (root->children[ch - 'a']) {
            child = root->children[ch - 'a'];
        } else { // create child and then move
            child = new TrieNode(ch);
            root->children[ch - 'a'] = child;
        }

        insert(child, str.substr(1));
    }

    void findAllSuggestions(TrieNode* root, vector<string>& temp, string str) {
        // base-case
        if (temp.size() >= 3) {
            return;
        }

        if (root->isTerminal) {
            // cout << root->ch << endl;
            temp.push_back(str);
            // return;
        }

        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            if (root->children[i]) {
                TrieNode* _root = root->children[i];
                // cout<< root->ch << endl;
                findAllSuggestions(_root, temp, str + c);
            }
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {

        vector<vector<string>> result;
        // create trie;
        TrieNode* root = new TrieNode('-');
        // insert products into trie
        for (int i = 0; i < products.size(); i++) {
            insert(root, products[i]);
        }

        int n = searchWord.size();
        string str;
        for (int i = 0; i < n; i++) {
            vector<string> temp;
            char lastCh = searchWord[i];
            str.push_back(lastCh);
            if (root->children[lastCh - 'a']) {
                root = root->children[lastCh - 'a'];
                findAllSuggestions(root, temp, str);
                result.push_back(temp);
            } else {
                while(i < n){
                 result.push_back(temp);
                 i++;
                }

                break;
            }
        }

        return result;
    }
};
