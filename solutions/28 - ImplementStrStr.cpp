class Solution {
public:
    int strStr(string haystack, string needle) {
        int hlen = haystack.length();
        int nlen = needle.length();
        for (int i = 0; i < hlen - nlen + 1; i++) {
            if (haystack.substr(i, nlen) == needle) {
                return i;
            }
        }
        return -1;
    }
};