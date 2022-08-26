class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> keyIndices;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                keyIndices.push_back(i);
            }
        }
        vector<int> kdistant;
        int last = -1;
        for (auto &i : keyIndices) {
            int j = i - k;
            while (j <= i + k) {
                if (last < j && j < n) {
                    kdistant.push_back(j);
                    last = j;
                }
                j++;
            }
        }
        return kdistant;
    }
};