class Solution {
public:
    int mirrorReflection(int p, int q) {
        int i = 0, count = 0;
        while (true) {
            i += q;
            count++;
            
            if (i % p == 0) {
                if (count % 2 == 0) {
                    if (i % (2 * p) != 0) {
                        return 2;
                    }
                } else {
                    if (i % (2 * p) == 0) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
};