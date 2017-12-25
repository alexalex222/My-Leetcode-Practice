class ValidWordAbbr {
private:
	set<string> dict;
	unordered_map<string, int> myMap;
public:
    ValidWordAbbr(vector<string> &dictionary) {
		for(string s : dictionary) {
			dict.insert(s);
			string abbrWord;
			string firstLetter(1, s[0]);
			string lastLetter(1, s[s.size() - 1]);
			if(s.size() == 1) {
				abbrWord = firstLetter;
			}
			else {	
				if(s.size() > 2) {
					abbrWord = firstLetter + to_string(s.size() - 2) + lastLetter;
				}
				else {
					abbrWord = firstLetter  + lastLetter;
				}
				if(myMap.find(abbrWord) == myMap.end()) {
					myMap.emplace(abbrWord, 1);
				}
				else {
					myMap[abbrWord]++;
				}
			}		
		}
    }

    bool isUnique(string word) {
        string abbrWord;
		string firstLetter(1, word[0]);
		string lastLetter(1, word[word.size() -1]);
		if(word.size() == 1) {
			abbrWord = firstLetter;
		}
		else if(word.size() > 2) {
			abbrWord = firstLetter + to_string(word.size() - 2) + lastLetter;
		}
		else {
			abbrWord = firstLetter + lastLetter;
		}

		if(myMap.find(abbrWord) == myMap.end()) {
			return true;
		}
		else if(myMap[abbrWord] == 1) {
			if(dict.find(word) != dict.end()) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
    }

	//Write a function to generate the generalized abbreviations of a word.
	vector<string> generateAbbreviations(string word) {
		vector<string> result;
		for (int i = 0; i < static_cast<int>(pow(2, word.size())); i++) {
			string out = "";
			int cnt = 0;
			int t = i;
			for (int j = 0; j < static_cast<int>(word.size()); j++) {
				if ((t & 1) == 1) {
					cnt++;
					if (j == static_cast<int>(word.size()) - 1) out += to_string(cnt);
				}
				else {
					if (cnt != 0) {
						out += to_string(cnt);
						cnt = 0;
					}
					out += word[j];
				}
				t = t >> 1;
			}
			result.push_back(out);
		}
		return result;
	}

	//Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.
	bool validWordAbbreviation(string word, string abbr) {
		int len1 = static_cast<int>(word.size());
		int len2 = static_cast<int>(abbr.size());
		int i = 0;
		int j = 0;
		while (i < len1 && j < len2) {
			if (abbr[j] == word[i]) {
				i++;
				j++;
			}
			else if (abbr[j] >= '1' && abbr[j] <= '9') {
				int num = 0;
				while (abbr[j] >= '0' && abbr[j] <= '9' && j < len2) {
					num = num * 10 + abbr[j] - '0';
					j++;
				}
				i += num;
			}
			else {
				return false;
			}
		}
		return (i == len1 && j == len2);
	}

	/*
	Given a target string and a set of strings in a dictionary, find an abbreviation of this target string
	with thesmallest possible length such that it does not conflict with abbreviations of the strings in the dictionary.
	*/
	string minAbbreviation(string target, vector<string>& dictionary) {
		auto q = generateAbbreviations2(target);
		while (!q.empty()) {
			auto p = q.top();
			q.pop();
			bool noConflict = true;
			for (string word : dictionary) {
				if (validWordAbbreviation(word, p.second)) {
					noConflict = true;
					break;
				}
			}
			if (noConflict) return p.second;
		}
		return "";
	}

	priority_queue < pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> generateAbbreviations2(string word) {
		priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> result;
		for (int i = 0; i < static_cast<int>(pow(2, word.size())); i++) {
			string abbr = "";
			int cnt = 0;
			int binRep = i;
			for (int j = 0; j < static_cast<int>(word.size()); j++) {
				if (binRep & 1) {
					cnt++;
					if (j == static_cast<int>(word.size()) - 1) abbr += to_string(cnt);
				}
				else {
					if (cnt > 0) {
						abbr += to_string(cnt);
						cnt = 0;
					}
					abbr += word[j];
				}
				binRep = binRep >> 1;
			}
			result.push(make_pair(static_cast<int>(abbr.size()), abbr));
		}
		return result;
	}
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
