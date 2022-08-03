class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> chars;
        int max_len = 0;
        
        if (s.length() <= 1)
            return s.length();
        
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (chars.find(s[j]) == chars.end()) {
                    chars.insert(s[j]);
                } else {
                    if (chars.size() > max_len) {
                        max_len = chars.size();
                    }
                    chars.clear();
                    break;
                }
            }
        }
        return max_len;
    }
};
