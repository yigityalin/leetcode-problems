class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            if (pq.size() < k) {
                pq.push({-nums[i], i});
            } else if (-nums[i] < pq.top().first) {
                pq.pop(); pq.push({-nums[i], i});
            }
        }
        
        vector<int> result;
        while (!pq.empty()) {
            int index = pq.top().second; pq.pop();
            result.push_back(index);
        }
        sort(result.begin(), result.end());
        for (int i = 0; i < k; i++) {
            result[i] = nums[result[i]];
        }
        return result;
    }
};