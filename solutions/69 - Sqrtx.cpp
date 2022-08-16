class Solution {
public:
    int mySqrt(int x) {
        long left = 0, right = x, mid, midsq;
        while (left <= right) {
            mid = (left + right) / 2;
            midsq = mid * mid;
            if (x >= (mid - 1) * (mid - 1) && x <= midsq) {
                return midsq == x ? mid : mid - 1;
            } else if (x > midsq) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return mid;
    }
};