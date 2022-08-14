class Solution {
public:
    int helper(int n, bool owned, bool allowed, vector<vector<vector<int>>> &profits, vector<int> &prices) {
        if (n == prices.size()) {
            return 0;
        } else {
            if (profits[n][owned][allowed] == -1) {
                int noAction = helper(n + 1, owned, true, profits, prices);
                int action = helper(n + 1, !owned, !owned, profits, prices);
                profits[n][owned][allowed] = max(noAction, allowed * (action + (owned ? prices[n] : -prices[n])));
            }
            return profits[n][owned][allowed];
        }
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> profits(prices.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        return helper(0, false, true, profits, prices);
    }
};