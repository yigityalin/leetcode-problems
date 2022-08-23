class Solution {
public:
    bool helper(int i, int j, string &s) {
        if (i >= j)            return true;
        else if (s[i] != s[j]) return false;
        else                   return helper(i + 1, j - 1, s);
    }
    
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            if (helper(0, words[i].length() - 1, words[i])) {
                return words[i];
            }
        }
        return "";
    }
};