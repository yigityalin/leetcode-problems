class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;
        for (auto &c : s) {
            counts[c]++;
        }
        bool oddExists = false;
        int n = 0;
        for (auto &entry : counts) {
            if (entry.second % 2 == 0) {
                n += entry.second;
            } else {
                n += entry.second - 1;
                oddExists = true;
            }
        }
        return n + oddExists;
    }
};