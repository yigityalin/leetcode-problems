class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        vector<int> counts(26, 0);
        for (auto &c : s) {
            counts[c - 'a']++;
        }
        for (int i = 0; i < n; i++) {
            if (counts[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};