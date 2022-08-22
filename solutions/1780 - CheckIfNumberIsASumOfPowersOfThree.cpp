class Solution {
public:
    bool checkPowersOfThree(int n) {
        int x = 1;
        while (x <= n / 3) x *= 3;
        if    (n % 3 == 1) n--;
        while (n) {
            if (n / x > 1) return false;
            if (n >= x)    n -= x;
            x /= 3;
        }
        return true;
    }
};