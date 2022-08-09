class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lengths(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] < nums[j]) {
                    lengths[j] = max(1 + lengths[i], lengths[j]);
                }
            }
        }
        return *max_element(lengths.begin(), lengths.end());
    }
};