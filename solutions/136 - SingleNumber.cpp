class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int single = nums[0];
        for (int i = 1; i < n; i++) {
            single ^= nums[i];
        }
        return single;
    }
};