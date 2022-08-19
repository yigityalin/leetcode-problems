class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; int right = height.size() - 1;
        int minlen = min(height[left], height[right]);
        int largest = (right - left) * minlen;
        if (height[left] < height[right]) left++;
        else                              right--;
        while (left < right) {
            int currlen = min(height[left], height[right]);
            if (currlen > minlen) {
                minlen = currlen;
                largest = max(largest, (right - left) * currlen);
            }
            if (height[left] < height[right]) left++;
            else                              right--;
        }
        return largest;
    }
};