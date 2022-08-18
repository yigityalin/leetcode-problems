class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> counts;
        for (auto &i : arr) {
            counts[i]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto &entry : counts) {
            pq.push({entry.second, entry.first});
        }
        int total = 0, count = 0;
        while (!pq.empty() && total < n / 2) {
            int x = pq.top().first;
            pq.pop();
            total += x;
            count++;
        }
        return count;
    }
};