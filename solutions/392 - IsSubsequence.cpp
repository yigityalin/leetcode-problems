class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        int i = 0, j = 0;
        while (i < n) {
            while (j < m - 1 && s[i] != t[j]) j++;
            if (s[i] != t[j]) return false;
            i++; j++;
        }
        return true;
    }
};