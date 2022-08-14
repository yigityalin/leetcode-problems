class Solution {
public:
    vector<string> split(string &s) {
        vector<string> words;
        string word;
        size_t position = 0;
        while ((position = s.find(' ')) != string::npos) {
            word = s.substr(0, position);
            words.push_back(word);
            s.erase(0, position + 1);
        }
        words.push_back(s);
        return words;
    }
    
    bool wordPattern(string pattern, string s) {
        vector<string> words = split(s);
        if (words.size() != pattern.length()) {
            return false;
        }
        unordered_map<char, vector<int>> indices;
        for (int i = 0; i < pattern.length(); i++) {
            indices[pattern[i]].push_back(i);
        }
        std::unordered_set<string> wordset;
        for (auto &entry : indices) {
            string word = words[entry.second[0]];
            if (wordset.count(word)) {
                return false;
            }
            wordset.insert(word);
            for (int i = 1; i < entry.second.size(); i++) {
                if (words[entry.second[i]] != word) {
                    return false;
                }
            }
        }
        return true;
    }
};