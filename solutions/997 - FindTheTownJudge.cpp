class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int **trustedCounts = new int*[n]();
        for (int i = 0; i < n; i++) {
            trustedCounts[i] = new int[2]();
        }

        for (vector<int> edge : trust) {
            int trustor = edge[0] - 1;
            int trustee = edge[1] - 1;
            trustedCounts[trustor][0] += 1;
            trustedCounts[trustee][1] += 1;
        }
        
        int judge = -1;
        for (int i = 0; (i < n); i++) {
            if ((trustedCounts[i][0] == 0) && (trustedCounts[i][1] == n - 1)) {
                judge = i + 1;
            }
            delete [] trustedCounts[i];
        }
        
        delete [] trustedCounts;
        return judge;
    }
};