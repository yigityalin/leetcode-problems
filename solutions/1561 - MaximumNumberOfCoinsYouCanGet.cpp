class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int sum = 0, i = n - 2;
        for (int j = 0; j < n / 3; j++) {
            sum += piles[i];
            i -= 2;
        }
        return sum;
    }
};