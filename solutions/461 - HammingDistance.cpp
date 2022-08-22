class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        x ^= y;
        while (x) {
            count += x & 1;
            x >>= 1;
        }
        return count;
    }
};