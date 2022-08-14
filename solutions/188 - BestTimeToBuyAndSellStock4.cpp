class Solution {
public:
    int helper(int n, int transactions, bool owned, vector<vector<vector<int>>> &profits, vector<int> &prices, const int &k) {
        if (n == prices.size() || transactions == 0) {
            return 0;
        } else {
            if (profits[n][transactions - 1][owned] == -1) {
                int noAction = helper(n + 1, transactions, owned, profits, prices, k);
                int action = helper(n + 1, transactions - owned, !owned, profits, prices, k);
                profits[n][transactions - 1][owned] = max(noAction, action + (owned ? prices[n] : -prices[n]));
            }
            return profits[n][transactions - 1][owned];
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> profits(prices.size(), vector<vector<int>>(k, vector<int>(2, -1)));
        return helper(0, k, false, profits, prices, k);
    }
};