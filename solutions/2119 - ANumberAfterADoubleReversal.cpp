class Solution {
public:
    bool isSameAfterReversals(int num) {
        if   (num == 0) return true;
        else            return num % 10;
    }
};