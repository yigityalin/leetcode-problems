class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> counts;
        for (auto &c : magazine) {
            counts[c]++;
        }
        for (auto &c : ransomNote) {
            if (counts[c] == 0) {
                return false;
            }
            counts[c]--;
        }
        return true;
    }
};