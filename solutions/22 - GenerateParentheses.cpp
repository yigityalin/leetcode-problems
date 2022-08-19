class Solution {
public:
    void helper(int open, int close, string current, vector<string> &parentheses) {
        if (open == 0 && close == 0) {
            parentheses.push_back(current);
        }
        if (open > 0) {
            helper(open - 1, close, current + '(', parentheses);
        }
        if (close > open) {
            helper(open, close - 1, current + ')', parentheses);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> parentheses;
        helper(n, n, "", parentheses);
        return parentheses;
    }
};