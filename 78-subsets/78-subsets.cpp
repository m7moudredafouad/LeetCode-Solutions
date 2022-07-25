class Solution {
    vector<int> tmp;
    void findSubsets(vector<int>& nums, vector<vector<int>>& db, int index) {
        if(index == nums.size()) {
            db.push_back(tmp);
            return;
        }
        findSubsets(nums, db, index + 1);
        tmp.push_back(nums[index]);
        findSubsets(nums, db, index + 1);
        tmp.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> db;
        findSubsets(nums, db, 0);
        return db;
    }
};