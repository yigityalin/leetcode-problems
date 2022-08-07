/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int helper(int left, int right) {
        int mid = left + (right - left) / 2;
        int result = guess(mid);
        if (result == 0) {
            return mid;
        } else if (result == -1) {
            return helper(left, mid - 1);
        } else if (result == 1) {
            return helper(mid + 1, right);
        } else {
            return -1;
        }
    }
    
    int guessNumber(int n) {
        return helper(1, n);
    }
};