class Solution {
public:
    bool isUnderAttack(vector<string> &board, int row, int column, const int &n) {
        for (int i = 0; i < column; i++) {
            if (board[row][i] == 'Q') {
                return true;
            }
        }
        for (int i = 0; i < row; i++) {
            if (board[i][column] == 'Q') {
                return true;
            }
        }
        for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return true;
            }
        }
        for (int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return true;
            }
        }
        return false;
    }
    
    void placeQueens(int &k, vector<string> board, vector<vector<string>> &boards, int row, const int &n) {
        if (row < n) {
            for (int column = 0; column < n; column++) {
                if (!isUnderAttack(board, row, column, n)) {
                    board[row][column] = 'Q';
                    placeQueens(k, board, boards, row + 1, n);
                    if (row == n - 1) {
                        boards.push_back(board);
                    }
                    board[row][column] = '.';
                }
            }
        } else {
            k++;
        }
    }
    
    int totalNQueens(int n) {
        int k = 0;
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> boards;
        placeQueens(k, board, boards, 0, n);
        return k;
    }
};