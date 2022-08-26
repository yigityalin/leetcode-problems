class Solution {
public:
    vector<int> count(int n) {
        vector<int> counts(10, 0);
        while (n) {
            counts[n % 10]++;
            n /= 10;
        }
        return counts;
    }
    
    bool equals(vector<int> x, vector<int> y) {
        int n = x.size();
        for (int i = 0; i < n; i++) {
            if (x[i] != y[i]) {
                return false;
            }
        }
        return true;
    }
        
    bool reorderedPowerOf2(int n) {
        auto counts = count(n);
        int power = 1;
        for (int i = 0; i < 30; i++) {
            if (equals(counts, count(power))) {
                return true;
            }
            power *= 2;
        }
        return false;
    }
};