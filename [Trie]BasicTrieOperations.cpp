#include <iostream>

using namespace std;

// TrieNode class
class TrieNode {
public:
	char data;
	TrieNode* children[26];
	bool isTerminal;

	TrieNode(char data) {
		this->data = data;
		for (int i = 0;i < 26;i++) {
			children[i] = NULL;
		}
		this->isTerminal = false;
	}
};

// insert function
void insertWord(TrieNode* root , string word) {

	//cout << word << endl;
	if (word.length() == 0) {
		root->isTerminal = true;
		return;
	}

	char ch = word[0];
	int index = ch - 'a';

	if (root->children[index] == NULL) {
		TrieNode* child = new TrieNode(ch);
		root->children[index] = child;
	}
	
	root = root->children[index];

	insertWord(root, word.substr(1));

}

//search function
bool searchWord(TrieNode* root,string word) {
	
	if (word.length() == 0) {
		if (root->isTerminal) return true;
		return false;
	}
	char ch = word[0];
	int index = ch - 'a';
	if (root->children[index] == NULL) {
		return false;
	}

	root = root->children[index];

	return searchWord(root, word.substr(1));

}

//delete function
void deleteWord(TrieNode* root, string word) {

	if (word.length() == 0) {
		root->isTerminal = false;
		return;
	}

	char ch = word[0];
	int index = ch - 'a';

	if (root->children[index] == NULL) {
		return;
	}
	root = root->children[index];

	deleteWord(root, word.substr(1));

}

int main()
{
	// intializing the root of TrieNode
	TrieNode* root = new TrieNode('a');


	// populate the trie
	insertWord(root, "tree");
	insertWord(root, "true");
	insertWord(root, "try");
	insertWord(root, "toy");
	insertWord(root, "wish");
	insertWord(root, "win");
	insertWord(root, "beer");
	insertWord(root, "best");
	insertWord(root, "bet");
	insertWord(root, "buy");

	// search a word in trie
	bool ans = searchWord(root,"tree");

	if (ans) {
		cout << "word present" << endl;
	}
	else {
		cout << "word not present" << endl;
	}

	//delete a word in a trie
	deleteWord(root, "tree");

	// check if word deleted successfully or not
	bool ans1 = searchWord(root, "tree");

	if (ans1) {
		cout << "word present" << endl;
	}
	else {
		cout << "word not present" << endl;
	}


	return 0;

}
