class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> counts;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int div, inc, num = 1, limit = sqrt(arr[i]) + 1;
            for (int j = 0; arr[j] < limit; j++) {
                div = arr[i] / arr[j];
                if (arr[i] % arr[j] == 0 && counts.find(div) != counts.end()) {
                    inc = (counts[div] * counts[arr[j]]) % mod;
                    inc = (inc * (1 + (div != arr[j]))) % mod;
                    num = (num + inc) % mod;
                }
            }
            counts[arr[i]] = num;
            count = (count + num) % mod;
        }
        return count % mod;
    }
};