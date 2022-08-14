class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 1, len = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                len++;
            } else {
                maxlen = max(len, maxlen);
                len = 1;
            }
        }
        return max(len, maxlen);
    }
};