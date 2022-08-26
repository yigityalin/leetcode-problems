class Solution {
public:
    set<int> primes = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 
        29, 31, 37, 41, 43, 47, 53, 59,
        61, 67, 71, 73, 79, 83, 89, 97
    };
    
    bool isThree(int n) {
        double sq = sqrt(n);
        if (sq - (int) sq == 0) {
            return primes.count((int) sq);
        } else {
            return false;
        }        
    }
};