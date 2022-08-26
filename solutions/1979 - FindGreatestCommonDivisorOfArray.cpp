class Solution {
public:
    int gcd(int a, int b) {
        if (a == 0) {
            return b;
        } else if (b == 0) {
            return a;
        } else if (a == b) {
            return a;
        } else if (a > b) {
            return gcd(a-b, b);
        } else {
            return gcd(a, b-a);
        }
    }
    
    int findGCD(vector<int>& nums) {
        int minnum = 1000, maxnum = 1;
        for (auto &num : nums) {
            minnum = min(num, minnum);
            maxnum = max(num, maxnum);
        }
        return gcd(minnum, maxnum);
    }
};