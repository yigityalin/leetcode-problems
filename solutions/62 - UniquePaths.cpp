class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(m , vector<int>(n , 0));
        return uniquePathsHelper(0, 0, m, n, paths);
    }
    
    int uniquePathsHelper(int i, int j, int m, int n, vector<vector<int>> &paths) {
        if ((i + 1 == m) || (j + 1 == n)) {
            return 1;
        } else if (paths[i][j] != 0) {
            return paths[i][j];
        } else {
            paths[i][j] = uniquePathsHelper(i + 1, j, m, n, paths)
                          + uniquePathsHelper(i, j + 1, m, n, paths);
            return paths[i][j];
        }
    }
};