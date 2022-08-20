class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int> pq;
        int s = 0, count = 0, current = startFuel;
        while (current < target) {
            while (s < n && stations[s][0] <= current) {
                pq.push(stations[s++][1]);
            }
            if (pq.empty()) {
                break;
            }
            current += pq.top(); pq.pop();
            count++;
        }
        return current >= target ? count : -1;
    }
};