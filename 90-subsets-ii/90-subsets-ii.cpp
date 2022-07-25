class Solution {
    vector<int> tmp;
    void findSubsets(vector<pair<int, int>> &nums, vector<vector<int>>& db, int fullSize, int index, int numElements) {
        if(index >= nums.size() || numElements >= fullSize) {
            db.push_back(tmp);
            return;
        }
        
        findSubsets(nums, db, fullSize, index + 1, numElements + 1);
        
        for(int i = 0; i < nums[index].second; i++) {
            tmp.push_back(nums[index].first);
            findSubsets(nums, db, fullSize, index+1, numElements + i + 1);
        }
        
        for(int i = 0; i < nums[index].second; i++) {
            tmp.pop_back();
        }
        
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> db;
        vector<pair<int, int>> theNums;
        
        
        theNums.push_back(make_pair(nums[0], 1));
        
        int j = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                theNums[j].second++;
            } else {
                j++;
                theNums.push_back(make_pair(nums[i], 1));
            }
        }
        
        findSubsets(theNums, db, nums.size(), 0, 0);
        return db;
    }
};