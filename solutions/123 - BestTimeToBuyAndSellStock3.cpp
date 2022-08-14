class Solution {
public:
    int helper(int n, int transactions, bool owned, vector<vector<vector<int>>> &profits, vector<int> &prices) {
        if (n == prices.size() || transactions == 0) {
            return 0;
        } else {
            if (profits[n][transactions - 1][owned] == -1) {
                int noAction = helper(n + 1, transactions, owned, profits, prices);
                int action = helper(n + 1, transactions - owned, !owned, profits, prices);
                profits[n][transactions - 1][owned] = max(noAction, action + (owned ? prices[n] : -prices[n]));
            }
            return profits[n][transactions - 1][owned];
        }
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> profits(prices.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        return helper(0, 2, false, profits, prices);
    }
};