class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for (int i = 0; i < strs[0].length(); i++) {
            char last = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j].length() <= i || strs[j][i] != last) {
                    return prefix;
                }
            }
            prefix += last;
        }
        return prefix;
    }
};