class Solution {
public:
    bool helper(int left, int right, int turn, int alice, int bob, 
                vector<vector<vector<int>>> &winners, vector<int> &piles) {
        if (left > right) {
            return alice > bob;
        } else {
            if (winners[turn][left][right] == -1) {
                if (turn == 0) {
                    winners[turn][left][right] =
                        helper(left + 1, right, 1, alice + piles[left], bob, winners, piles)
                        || helper(left, right - 1, 1, alice + piles[right], bob, winners, piles);
                } else if (turn == 1) {
                    winners[turn][left][right] =
                        helper(left + 1, right, 0, alice, bob + piles[left], winners, piles)
                        || helper(left, right - 1, 0, alice, bob + piles[right], winners, piles);
                }
            }
            return winners[turn][left][right];
        }
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> winners(2, vector<vector<int>>(n, vector<int>(n, -1)));
        return helper(0, n - 1, 0, 0, 0, winners, piles);
    }
};