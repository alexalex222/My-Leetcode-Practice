#pragma once
/*
Design an algorithm to encode a list of strings to a string. 
The encoded string is then sent over the network and is decoded back to the original list of strings.
The string may contain any possible characters out of 256 valid ascii characters. 
Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
*/
class Codec {
public:

	// Encodes a list of strings to a single string.
	string encode(vector<string>& strs) {
		string encoded = "";
		for (string s : strs) {
			int len = static_cast<int>(s.size());
			encoded = encoded + to_string(len) + "#" + s;
		}
		return encoded;
	}

	// Decodes a single string to a list of strings.
	vector<string> decode(string s) {
		vector<string> result;
		size_t startPos = 0;
		size_t totLen = s.size();
		while (startPos < totLen) {
			size_t poundPos = s.find("#", startPos);
			string tempString = s.substr(startPos, poundPos - startPos + 1);
			size_t curLen = stoi(tempString);
			tempString = s.substr(poundPos + 1, curLen);
			result.push_back(tempString);
			startPos = poundPos + 1 + curLen;
		}
		return result;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

