class Solution {
public:
    bool helper(bool allowed, int i, int j, string &s) {
        if (i >= j)            return true;
        else if (s[i] == s[j]) return helper(allowed, i + 1, j - 1, s);
        else {
            if (allowed) return helper(false, i + 1, j, s) || helper(false, i, j - 1, s);
            else         return false;
        } 
    }
    
    bool validPalindrome(string s) {
        return helper(true, 0, s.length() - 1, s);
    }
};