class Solution {
public:
    bool isAdjacent(const string &word1, const string &word2) {
        int diff = 0;
        for (int i = 0; i < word1.length(); i++) {
            if (word1[i] != word2[i]) {
                diff++;
            }
            if (diff > 1) {
                return false;
            }
        }
        return diff == 1;
    }
    
    vector<vector<int>> constructGraph(vector<string>& wordList) {
        int n = wordList.size();
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isAdjacent(wordList[i], wordList[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        return graph;
    }
    
    vector<vector<int>> bfs(int begin, vector<vector<int>> &graph) {
        int n = graph.size();
        vector<vector<int>> parents(n, vector<int>());
		vector<int> distances(n, INT_MAX);
		
		queue<int> q; 
		q.push(begin);

		distances[begin] = 0;
		parents[begin] = {-1};

		while (!q.empty()){
			int curr = q.front(); q.pop();
			
			for (int &node : graph[curr]){
				if (distances[curr] + 1 < distances[node]) {
					distances[node] = distances[curr] + 1;
					q.push(node);
					parents[node].clear();
					parents[node].push_back(curr);
				} else if (distances[curr] + 1 == distances[node]) {
					parents[node].push_back(curr);
                }
			}
		}
        return parents;
	}
    
    void shortestPaths(int node, vector<int> &current, vector<vector<int>> &paths, vector<vector<int>> &parents) {
		if (node == -1){
			paths.push_back(current);
		} else {
            for (int &parent : parents[node]){ 
                current.push_back(parent);
                shortestPaths(parent, current, paths, parents);
                current.pop_back();
            }
        }
	}
    
    vector<vector<int>> shortestPaths(int node, vector<vector<int>> &parents) {
        vector<vector<int>> paths;
        vector<int> current;
        shortestPaths(node, current, paths, parents);
        return paths;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int begin = -1, end = -1;
        for (int i = 0; i < n; i++) {
            if (wordList[i] == beginWord) {
                begin = i;
            } else if (wordList[i] == endWord) {
                end = i;
            }
        }
        if (end == -1) {
            return {};
        }
        if (end != n - 1) {
            string tmp = wordList[end];
            wordList[end] = wordList[n - 1];
            wordList[n - 1] = tmp;
            if (begin == n - 1) {
                begin = end;
            }
            end = n - 1;
        }
        if (begin == -1) {
            wordList.emplace(wordList.begin(), beginWord);
            begin++; end++; n++; 
        } else if (begin != 0) {
            string tmp = wordList[0];
            wordList[0] = wordList[begin];
            wordList[begin] = tmp;
            begin = 0;
        }
        auto graph = constructGraph(wordList);
        auto parents = bfs(begin, graph);
        auto paths = shortestPaths(n - 1, parents);
        
        vector<vector<string>> result(paths.size(), vector<string>());
        
        for (int i = 0; i < paths.size(); i++) {
            vector<int> path = paths[i];
            for (int j = path.size() - 2; j >= 0; j--) {
                result[i].push_back(wordList[path[j]]);
            }
            result[i].push_back(wordList[end]);
        }

        return result;
    }
};