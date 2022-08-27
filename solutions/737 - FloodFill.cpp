class Solution {
public:
    void helper(vector<vector<int>> &image, int sr, int sc, const int &prev, const int &color) {
        if (image[sr][sc] == prev) {
            image[sr][sc] = color;
            if (sr > 0)                   helper(image, sr - 1, sc, prev, color);
            if (sc > 0)                   helper(image, sr, sc - 1, prev, color);
            if (sr < image.size() - 1)    helper(image, sr + 1, sc, prev, color);
            if (sc < image[0].size() - 1) helper(image, sr, sc + 1, prev, color);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prev = image[sr][sc];
        if (prev != color) {
            helper(image, sr, sc, prev, color);
        }
        return image;
    }
};