class Solution {
public:
    int maxPower(string s) {
        int i = 0, n = s.length();
        int power = 0;
        while (i < n - power) {
            int j = 1;
            while (s[i] == s[i + j]) j++;
            power = max(power, j);
            i += j;
        }
        return power;
    }
};