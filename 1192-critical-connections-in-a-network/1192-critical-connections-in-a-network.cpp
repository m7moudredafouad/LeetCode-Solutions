class Solution {
    
private:
    int time = 0;
    
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &timeToVisit,
            vector<int> &lowLink, vector<vector<int>> &criticals, int node, int parent) {
        
        visited[node] = true;
        timeToVisit[node] = lowLink[node] = time++;
        
        for(auto &nodeX : graph[node]) {
            if(nodeX == parent) continue;
            
            if(visited[nodeX] == false) {
                dfs(graph, visited, timeToVisit, lowLink, criticals, nodeX, node);
                
                lowLink[node] = min(lowLink[node], lowLink[nodeX]);
                
                if(timeToVisit[node] < lowLink[nodeX]) {
                    criticals.push_back({node, nodeX});
                }
                
            } else {
                lowLink[node] = min(lowLink[node], timeToVisit[nodeX]);
            }
        }
        
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        vector<vector<int>> criticals;

        vector<bool> visited(n, false);
        vector<int> timeToVisit(n, 0);
        vector<int> lowLink(n, false);
        
        for(auto &con : connections) {
            graph[con[0]].push_back(con[1]);
            graph[con[1]].push_back(con[0]);
        }
        
        for(auto i = 0; i < n; i++) {
            if(visited[i] == false) {
                dfs(graph, visited, timeToVisit, lowLink, criticals, i, i);
            }
        }
        
        return criticals;
    }
};