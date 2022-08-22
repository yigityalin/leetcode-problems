class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counts = {0};
        for (int i = 1; i <= n; i++) {
            counts.push_back(counts[i / 2] + i % 2);
        }
        return counts;
    }
};