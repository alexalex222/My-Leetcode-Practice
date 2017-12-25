using namespace std;
class WordDictionary {
private:
	TrieNode* root;
public:
	WordDictionary() {
		root = new TrieNode;
	}

    // Adds a word into the data structure.
    void addWord(string word) {
		TrieNode* node = root;
		for(char c : word) {
			if(!node->children[c - 'a']) {
				node->children[c - 'a'] = new TrieNode();
			}
			node = node->children[c - 'a'];
		}
		node->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
		return dfsWord(root, word, 0);
    }

	bool dfsWord(TrieNode* dict, string word, int start) {
		if(dict->isWord && (start == static_cast<int>(word.size()))) {
			return true;
		}
		if(start >= static_cast<int>(word.size())) {
			return false;
		}
		char c = word[start];
		if(c == '.') {
			bool tFind = false;
			for(int j = 0; j < 26; j++) {
				if(dict->children[j]) {
					if(dfsWord(dict->children[j], word, start+1)) {
						tFind = true;
						break;
					}
				}
			}
			if(tFind) {
				return true;
			}
		}
		else {
			if(dict->children[c - 'a']) {
				return dfsWord(dict->children[c - 'a'], word, start + 1);
			}
			else {
				return false;
			}
		}
		return false;
	}
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
