class Solution {
public:
    vector<string> table = {".-","-...","-.-.","-..",".",
                            "..-.","--.","....","..",".---",
                            "-.-",".-..","--","-.","---",".--.",
                            "--.-",".-.","...","-","..-","...-",
                            ".--","-..-","-.--","--.."};
    
    int uniqueMorseRepresentations(vector<string>& words) {
        int n = words.size();
        unordered_set<string> transformations;
        for (int i = 0; i < n; i++) {
            string transformation = "";
            for (int j = 0; j < words[i].size(); j++) {
                transformation += table[words[i][j] - 'a'];
            }
            transformations.insert(transformation);
        }
        return transformations.size();
    }
};