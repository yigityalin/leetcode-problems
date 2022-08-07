class Solution {
public:
    int helper(int i, int j, vector<vector<int>> &sums, vector<vector<int>> &grid) {
        if (sums[i][j] == -1) {
            if (i == grid.size() - 1 && j == grid[0].size() - 1) {
                sums[i][j] = grid[i][j];
            } else if (i == grid.size() - 1) {
                sums[i][j] = grid[i][j] + helper(i, j + 1, sums, grid);
            } else if (j == grid[0].size() - 1) {
                sums[i][j] = grid[i][j] + helper(i + 1, j, sums, grid);
            } else {
                sums[i][j] = grid[i][j] + min(
                    helper(i, j + 1, sums, grid),
                    helper(i + 1, j, sums, grid)
                );
            }
        }
        return sums[i][j];
    }
        
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> sums(grid.size(), vector<int>(grid[0].size(), -1));
        return helper(0, 0, sums, grid);
    }
};