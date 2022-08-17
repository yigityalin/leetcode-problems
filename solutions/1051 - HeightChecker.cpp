class Solution {
public:
    int heightChecker(vector<int>& heights) {
        map<int, int> counts;
        for (auto &h : heights) {
            counts[h]++;
        }
        
        vector<int> expected;
        for (auto &entry : counts) {
            for (int i = 0; i < entry.second; i++) {
                expected.push_back(entry.first);
            }
        }
        
        int n = heights.size(), result = 0;
        for (int i = 0; i < n; i++) {
            if (heights[i] != expected[i]) {
                result++;
            }
        }
        return result;
    }
};