class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        for (int i = 0; i < m + n - 1; i++) {
            int x, y;
            if (i % 2 == 0) {
                x = max(0, i - m + 1) ; y = min(i, m - 1);
                while (x < n && y >= 0) {
                    result.push_back(mat[y][x]);
                    x++; y--;
                }
            } else {
                x = min(i, n - 1); y = max(0, i - n + 1);
                while (x >= 0 && y < m) {
                    result.push_back(mat[y][x]);
                    x--; y++;
                }
            }
        }
        return result;
    }
};