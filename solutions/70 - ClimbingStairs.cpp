class Solution {
public:
    int climbStairs(int n) {
        int x = 1, y = 1;
        while (n > 1) {
            int tmp = x;
            x = y;
            y += tmp; 
            n--;
        }
        return y;
    }
};