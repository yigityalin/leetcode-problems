class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left, right;
        int maxHeight = 0, total = 0;
        for (int i = 0; i < height.size(); i++) {
            maxHeight = max(height[i], maxHeight);
            left.push_back(maxHeight);
        }
        maxHeight = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            maxHeight = max(height[i], maxHeight);
            right.push_back(maxHeight);
        }
        for (int i = 0; i < height.size(); i++) {
            total += min(left[i], right[height.size() - i - 1]) - height[i];
        }
        return total;
    }
};