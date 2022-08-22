class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool prev = n & 1; n >>= 1;
        while (n) {
            bool curr = n & 1;
            if (prev == curr) {
                return false;
            }
            prev = curr;
            n >>= 1;
        }
        return true;
    }
};