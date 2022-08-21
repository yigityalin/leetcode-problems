class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        string result = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != result.back()) {
                result.push_back(s[i]);
            } else {
                result.pop_back();
            }
        }
        return result;
    }
};