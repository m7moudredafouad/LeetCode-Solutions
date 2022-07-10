class Solution {
    int minCost(vector<int>& cost, vector<int>& db, int index) {
        if(index >= cost.size()) return 0;
        if(db[index] != -1) return db[index];
        
        return db[index] = cost[index] + min(
            minCost(cost, db, index + 1),
            minCost(cost, db, index + 2)
        );
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> db(cost.size(), -1);
        minCost(cost, db, 0);
        return min(db[0], db[1]);
    }
};