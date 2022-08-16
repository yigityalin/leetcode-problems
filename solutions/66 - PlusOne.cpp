class Solution {
public:
    void helper(int index, int &carry, vector<int> &digits) {
        digits[index] += carry;
        digits[index] %= 10;
        carry = carry && digits[index] == 0;
    }
    
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        digits[n]++;
        digits[n] %= 10;
        int carry = digits[n] == 0;
        for (int i = n - 1; i >= 1; i--) {
            helper(i, carry, digits);
        }
        if (n > 0) {
            helper(0, carry, digits);
        }
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};