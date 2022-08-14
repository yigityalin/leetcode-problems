class Solution {
public:
    int helper(int sum, int n, vector<unordered_map<int, int>> &counts, vector<int> &nums, const int &target, const int &total) {
        if (n == nums.size()) {
            return sum == target;
        } else {
            if (!counts[n].count(sum)) {
                int add = helper(sum + nums[n], n + 1, counts, nums, target, total);
                int sub = helper(sum - nums[n], n + 1, counts, nums, target, total);
                counts[n][sum] = add + sub;
            }
            return counts[n][sum];
        }
    }
        
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int &i : nums) {
            sum += i;
        }
        if (target > sum || (sum - target) % 2 == 1) {
            return 0;
        } else {
            int total = 2 * sum + 1;
            vector<unordered_map<int, int>> counts(nums.size(), unordered_map<int, int>());
            return helper(0, 0, counts, nums, target, total);
        }
    }
};