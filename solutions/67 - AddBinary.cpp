class Solution {
public:
    string addBinary(string a, string b) {
        int ia = a.length() - 1;
        int ib = b.length() - 1;
        string s = "";
        int carry = 0;
        while (ia >= 0 || ib >= 0) {
            int x = (ia >= 0 ? a[ia] : '0') - '0';
            int y = (ib >= 0 ? b[ib] : '0') - '0';
            int n = carry + x + y;
            s.insert(0, 1, n % 2 + '0');
            carry = n / 2;
            ia--; ib--;
        }
        if (carry) {
            s.insert(0, 1, '1');
        }
        return s;
    }
};