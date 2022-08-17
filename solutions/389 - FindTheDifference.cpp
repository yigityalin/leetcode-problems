class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length();
        int letter = t[n] - 'a';
        for (int i = 0; i < n; i++) {
            letter ^= s[i] - 'a';
            letter ^= t[i] - 'a';
        }
        return letter + 'a';
    }
};