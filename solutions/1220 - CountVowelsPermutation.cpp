class Solution {
public:
    int helper(const int &n, const int &mod, vector<vector<int>> &counts, char last, int len) {
        if (n == len) {
            return 1;
        } else if (last == 'a') {
            if (counts[len][0] == -1) {
                counts[len][0] = helper(n, mod, counts, 'e', len + 1) % mod;
            }
            return counts[len][0];
        } else if (last == 'e') {
            if (counts[len][1] == -1) {
                counts[len][1] = helper(n, mod, counts, 'a', len + 1) % mod;
                counts[len][1] = (counts[len][1] + helper(n, mod, counts, 'i', len + 1)) % mod;
            } 
            return counts[len][1];
        } else if (last == 'i') {
            if (counts[len][2] == -1) {
                counts[len][2] = helper(n, mod, counts, 'a', len + 1) % mod;
                counts[len][2] = (counts[len][2] + helper(n, mod, counts, 'e', len + 1)) % mod;
                counts[len][2] = (counts[len][2] + helper(n, mod, counts, 'o', len + 1)) % mod;
                counts[len][2] = (counts[len][2] + helper(n, mod, counts, 'u', len + 1)) % mod;
            }
            return counts[len][2];
        } else if (last == 'o') {
            if (counts[len][3] == -1) {
                counts[len][3] = helper(n, mod, counts, 'i', len + 1) % mod;
                counts[len][3] = (counts[len][3] + helper(n, mod, counts, 'u', len + 1)) % mod;
            }
            return counts[len][3];
        } else if (last == 'u') {
            if (counts[len][4] == -1) {
                counts[len][4] = helper(n, mod, counts, 'a', len + 1) % mod;
            }
            return counts[len][4];
        } else {
            return 0;
        }
    }
        
    int countVowelPermutation(int n) {
        int mod = 1e9 + 7;
        vector<vector<int>> counts(n, vector<int>(5, -1));
        int total = helper(n, mod, counts, 'a', 1) % mod;
        total = (total + helper(n, mod, counts, 'e', 1)) % mod;
        total = (total + helper(n, mod, counts, 'i', 1)) % mod;
        total = (total + helper(n, mod, counts, 'o', 1)) % mod;
        total = (total + helper(n, mod, counts, 'u', 1)) % mod;
        return total;
    }
};