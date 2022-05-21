class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> *list = createAdjacencyList(n, edges);
        bool visited[n];

        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }
        
        return validPathHelper(n, list, visited, source, destination);
    }
    
    bool validPathHelper(int n, vector<int> *list, bool *visited, int source, int destination) {
        visited[source] = true;
        
        if (source == destination) {
            return true;
        }
        
        bool isValid = false;
        
        for (int i = 0; (!isValid) && (i < list[source].size()); i++) {
            if (!visited[list[source][i]]) {
                isValid = isValid || validPathHelper(n, list, visited, list[source][i], destination);
            }
        }
        
        return isValid;
    }
    
    vector<int>* createAdjacencyList(int n, vector<vector<int>>& edges) {
        auto list = new vector<int>[n]();
        
        for (vector<int> edge : edges) {
            int vertex1 = edge[0];
            int vertex2 = edge[1];
            
            list[vertex1].push_back(vertex2);
            list[vertex2].push_back(vertex1);
        }
        
        return list;
    }
};