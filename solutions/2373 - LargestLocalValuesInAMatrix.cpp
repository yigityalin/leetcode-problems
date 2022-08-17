class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>());
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                int maximum = INT_MIN;
                for (int k = 0; k < 3; k++) {
                    for (int m = 0; m < 3; m++) {
                        maximum = max(maximum, grid[i + k][j + m]);
                    }
                }
                maxLocal[i].push_back(maximum);
            }
        }
        return maxLocal;
    }
};