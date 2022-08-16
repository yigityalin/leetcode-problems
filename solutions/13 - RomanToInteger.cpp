class Solution {
public:
    unordered_map<char, int> s2i {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };
    
    int romanToInt(string s) {
        int n = s.length();
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (s2i[s[i]] < s2i[s[i + 1]]) {
                result -= s2i[s[i]];
            } else {
                result += s2i[s[i]];
            }
        }
        return result;
    }
};