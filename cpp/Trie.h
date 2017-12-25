using namespace std;

#ifndef TRIE_H
#define TRIE_H
class TrieNode {
public:
	bool isWord;
	vector<TrieNode*> children;
	vector<int> indexes;
    // Initialize your data structure here.
    TrieNode() {
		isWord = false;
		children = vector<TrieNode*>(26, NULL);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
		TrieNode* node = root;
		for(int i = 0; i < static_cast<int>(word.size()); i++) {
			if(node->children[word[i] - 'a'] == NULL) {
				node->children[word[i] - 'a'] = new TrieNode();
			}
			node = node->children[word[i] - 'a'];
		}
		node->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
		TrieNode* node = root;
		for(char c : word) {
			if(node) {
				node = node->children[c - 'a'];
			}
			else {
				break;
			}
		}
		if(node) {
			return node->isWord;
		}
		else {
			return false;
		}
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
		TrieNode* node = root;
		for(char c : prefix) {
			if(node) {
				node = node->children[c - 'a'];
			}
			else {
				break;
			}
		}
		if(node) {
			return true;
		}
		else {
			return false;
		}
    }


private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

#endif