class Solution {
public:
    bool helper(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count == 2
            || count == 3
            || count == 5
            || count == 7
            || count == 11
            || count == 13
            || count == 17
            || count == 19;
    }
    
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            count += helper(i);
        }
        return count;
    }
};