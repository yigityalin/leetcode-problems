class Solution {
public:
    int helper(vector<vector<int>> &grid, int i, int j) {
        int count = 4;
        if (i > 0 && grid[i - 1][j] == 1)                  count--;
        if (j > 0 && grid[i][j - 1] == 1)                  count--;
        if (i < grid.size() - 1 && grid[i + 1][j] == 1)    count--;
        if (j < grid[0].size() - 1 && grid[i][j + 1] == 1) count--;
        return count;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    perimeter += helper(grid, i, j);
                }
            }
        }
        return perimeter;
    }
};