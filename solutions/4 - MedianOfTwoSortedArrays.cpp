class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0;
        int i2 = 0;
        int i = 0;
        int arr_length = nums1.size() + nums2.size();
        int *arr = new int[arr_length];
        
        while (i1 < nums1.size() && i2 < nums2.size()) {
            if (nums1[i1] < nums2[i2]) {
                arr[i] = nums1[i1];
                i1++;
            }
            else {
                arr[i] = nums2[i2];
                i2++;
            }
            i++;
        }
        
        while (i1 < nums1.size()) {
            arr[i] = nums1[i1];
            i++;
            i1++;
        }
        
        while (i2 < nums2.size()) {
            arr[i] = nums2[i2];
            i++;
            i2++;
        }
        
        if (arr_length % 2 == 1) {
            return arr[arr_length / 2];
        }
        else {
            return (arr[arr_length / 2 - 1] + arr[arr_length / 2]) / 2.0;
        }
    }
};