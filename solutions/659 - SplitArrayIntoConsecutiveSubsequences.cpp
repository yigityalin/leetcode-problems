class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> counts, subsequences;
        for (auto &i : nums) {
            counts[i]++;
        }
        for (auto &i : nums) {
            if (counts[i] > 0) {
                if (subsequences[i - 1] > 0) {
                    counts[i]--;
                    subsequences[i - 1]--;
                    subsequences[i]++;
                } else if (counts[i + 1] > 0 && counts[i + 2] > 0) {
                    counts[i]--;
                    counts[i + 1]--;
                    counts[i + 2]--;
                    subsequences[i + 2]++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};