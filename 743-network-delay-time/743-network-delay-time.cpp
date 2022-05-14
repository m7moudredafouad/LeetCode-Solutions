class Solution {    
    void traverseGraph(vector<queue<pair<int, int>>>&graph, vector<int>&visitCost, int parent, int current, int nextCost) {     
        
        if(nextCost < visitCost[current]) {
            visitCost[current] = nextCost;
            // cout << current+1 << " >> " << nextCost << endl;

        }
        nextCost = visitCost[current];                
        pair<int, int> *tmp;
        
        while(!graph[current].empty()) {
            tmp = &(graph[current].front());
            graph[current].pop();
            
            // if(parent == tmp->first) return;
            cout << current+1 << " >> " <<tmp->first+1 << endl;

            traverseGraph(graph, visitCost, current, tmp->first, (nextCost + tmp->second));
        }
    }    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // stack of pairs of <nextNode, weight>
        // vector<queue<pair<int, int>>> graph(n);
        vector<vector<pair<int, int>>> graph(n);
        vector<int> visitCost(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int x = -1, totalSum = 0;

        while(++x < times.size()) {
            // graph[times[x][0]-1].push(make_pair(times[x][1] - 1,times[x][2]));
            graph[times[x][0]-1].push_back(make_pair(times[x][1] - 1,times[x][2]));

        }
        
        visitCost[k-1] = 0;        
        pq.push(make_pair(k-1, 0));        
        while (!pq.empty()) {
            pair<int,int> x = pq.top();
            pq.pop();
            
            for (auto neighbor : graph[x.first]) {
                int cost = visitCost[x.first] + neighbor.second;
                if (cost < visitCost[neighbor.first]) {
                    visitCost[neighbor.first] = cost;
                    pq.push(make_pair(neighbor.first, cost));
                }
            }            
        } 
        
        // traverseGraph(graph, visitCost, INT_MIN, k-1, 0);
        
        x = -1;
        while(++x < n) {
            cout << x+1 << " : " << visitCost[x] << endl;
            if(visitCost[x] == INT_MAX) return -1; 
            totalSum = max(visitCost[x], totalSum);
        }
        
        return totalSum;
    }
};