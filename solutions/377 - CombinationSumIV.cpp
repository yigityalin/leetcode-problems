class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        map<int, int> sums;
        return helper(sums, nums, target);
    }
    
    int helper(map<int, int> &sums, vector<int> &nums, int target) {
        if (target < 0) {
            return 0;
        } else if (target == 0) {
            return 1;
        } else {
            if (sums.find(target) != sums.end()) {
                return sums.find(target)->second;
            } else {
                int sum = 0;
                for (int i = 0; i < nums.size(); i++) {
                    sum += helper(sums, nums, target - nums[i]);
                }
                sums.insert({target, sum});
                return sum;
            }
        }
    }
};