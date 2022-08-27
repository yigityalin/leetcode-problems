class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sums(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sums[i][j] = sums[i][j - 1] + sums[i - 1][j]
                             - sums[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        int maxSum = INT_MIN;
        for (int il = 1; il <= m; il++) {
            for (int ih = il; ih <= m; ih++) {
                for (int jl = 1; jl <= n; jl++) {
                    for (int jh = jl; jh <= n; jh++) {
                        int sum = sums[ih][jh] - sums[ih][jl - 1]
                                  - sums[il - 1][jh] + sums[il - 1][jl - 1];
                        if (sum <= k) {
                            maxSum = max(sum, maxSum);
                        }
                        if (sum == k) {
                            return sum;
                        }
                    }
                }
            }
        }
        return maxSum;
    }
};