class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return 0;
        }
        int n_digits = 0;
        int n = x;
        while (n != 0) {
            n /= 10;
            n_digits++;
        }
        
        int div = n_digits / 2;
        for (int i = 0; i < div; i++) {
            n = (int) pow(10, n_digits - 1);
            if (x / n != x % 10) {
                return false;
            }
            n_digits -= 2;
            x %= n;
            x /= 10;
        }
        return true;
    }
};