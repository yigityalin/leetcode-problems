class Solution {
public:
    bool isDone(string s) {
        for (auto &c : s) {
            if (c != '?') {
                return false;
            }
        }
        return true;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        int n = stamp.length(), m = target.length();
        vector<int> result;
        while (!isDone(target)) {
            bool added = false;
            for (int i = 0; i < m - n + 1; i++) {
                if (!isDone(target.substr(i, n))) {
                    int j = 0;
                    while (j < n && (target[i + j] == stamp[j] || target[i + j] == '?')) {
                        j++;
                    }
                    if (j == n) {
                        for (j = 0; j < n; j++) {
                            target[i + j] = '?';
                        }
                        result.push_back(i);
                        added = true;
                    }
                }
            }
            
            if (!added) {
                return {};
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};