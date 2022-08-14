class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int nwords = words.size();
        int wordlength = words[0].size();
        int slength = s.length();
        int length = nwords * wordlength;
        
        unordered_set<int> indices;
        if (length <= slength) { 
            unordered_map<string, int> counts;
            for (auto &word : words) {
                counts[word]++;
            }
            for (int i = 0; i < slength - length + 1; i++) {
                if (indices.count(i - wordlength)) {
                    if (s.substr(i - wordlength, wordlength)
                        == s.substr(i + length - wordlength, wordlength)) {
                        indices.insert(i);
                    }
                } else {
                    auto countsCopy = counts;
                    int j = i;
                    while (j < i + length) {
                        if (--countsCopy[s.substr(j, wordlength)] == -1) {
                            break;
                        }
                        j += wordlength;
                    }
                    if (j == i + length) {
                        indices.insert(i);
                    }
                }
            }
        }
        return vector<int>(indices.begin(), indices.end());
    }
};