class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        } else {
            int p = floor(log2(n)) + 1;
            return pow(2, p) - n - 1;
        }
    }
};