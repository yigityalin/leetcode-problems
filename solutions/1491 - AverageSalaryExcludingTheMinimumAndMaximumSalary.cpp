class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int maxsalary = 1000, minsalary = 1e6;
        double sum = 0; 
        for (auto &i : salary) {
            maxsalary = max(i, maxsalary);
            minsalary = min(i, minsalary);
            sum += i;
        }
        return (sum - maxsalary - minsalary) / (n - 2);
    }
};