class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxnum = prices[n - 1], maxprofit = 0;
        for (int i = n - 2; i >= 0; i--) {
            maxprofit = max(maxprofit, maxnum - prices[i]);
            maxnum = max(maxnum, prices[i]);
        }
        return maxprofit;
    }
};