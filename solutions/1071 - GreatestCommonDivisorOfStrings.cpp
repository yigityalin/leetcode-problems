class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(); int m = str2.size();
        int t = min(n, m);
        for (int i = t; i > 0; i--) {
            if (n % i != 0 || m % i != 0) {
                continue;
            }
            string gcd = str1.substr(0, i);
            bool isDivisor = true;
            for (int j = i; j < n; j += i) {
                if (str1.substr(j, i) != gcd) {
                    isDivisor = false;
                }
            }
            for (int j = 0; isDivisor && j < m; j += i) {
                if (str2.substr(j, i) != gcd) {
                    isDivisor = false;
                }
            }
            if (isDivisor) {
                return gcd;
            }
        }
        return "";
    }
};