class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n % 2 == 1) {
            return false;
        }
        stack<char> stack;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
            } else {
                if (stack.empty()) {
                    return false;
                }
                char top = stack.top(); stack.pop();
                if ((top == '(' && s[i] != ')')
                    || (top == '{' && s[i] != '}')
                    || (top == '[' && s[i] != ']')) {
                    return false;
                } 
            }
        }
        return stack.empty();
    }
};