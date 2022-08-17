class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};
        for (int i = 1; i < rowIndex + 1; i++) {
            row.push_back(row[i-1] * (rowIndex - i + 1.0) / i);
        }
        return row;
    }
};