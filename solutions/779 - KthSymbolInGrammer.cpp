class Solution {
public:
    int kthGrammar(int n, int k) {
        if      (k == 1)     return 0;
        else if (k % 2 == 0) return !kthGrammar(n - 1, k / 2);
        else                 return kthGrammar(n - 1, (k + 1) / 2);
    }
};