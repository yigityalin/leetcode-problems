class Solution {
public:
    void update(const int &n, const vector<vector<int>> &matrix,
                int &i, int &j, int &direction) {
        if (direction == 0) {
            if (j == n - 1 || matrix[i][j + 1] != 0) {
                i++; direction = 1;
            } else {
                j++;
            }
        } else if (direction == 1) {
            if (i == n - 1 || matrix[i + 1][j] != 0) {
                j--; direction = 2;
            } else {
                i++;
            }
        } else if (direction == 2) {
            if (j == 0 || matrix[i][j - 1] != 0) {
                i--; direction = 3;
            } else {
                j--;
            }
        } else if (direction == 3) {
            if (i == 0 || matrix[i - 1][j] != 0) {
                j++; direction = 0;
            } else {
                i--;
            }
        }
    }
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int direction = 0;
        int total = n * n, x = 1, i = 0, j = 0;
        while (x <= total) {
            matrix[i][j] = x;
            update(n, matrix, i, j, direction);
            x++;
        }
        return matrix;
    }
};