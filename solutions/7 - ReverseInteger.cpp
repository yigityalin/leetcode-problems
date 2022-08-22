class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        while (x) {
            int digit = abs(x % 10);
            if ((reversed > (INT_MAX - digit) / 10 )
                || (reversed < (INT_MIN + digit) / 10)) {
                return 0;
            }
            reversed *= 10;
            reversed += x % 10;
            x /= 10;
        }
        return reversed;
    }
};