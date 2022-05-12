class Solution {
  private: 
  void findPermutation(vector<pair<int, int>>& nums, vector<vector<int>> &addHere, vector<int>& currPerm, int remainingLength) {
    if(remainingLength == 0) {
      addHere.push_back(currPerm);
      return;
    }
    
    for(int i = 0; i < nums.size(); i++) {
      if(nums[i].second > 0) {
        nums[i].second--;
        currPerm.push_back(nums[i].first);
        findPermutation(nums, addHere, currPerm, remainingLength - 1);
        currPerm.pop_back();
        nums[i].second++;
      }
    }
  }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> thePerms;
      vector<int> tmpPerms;
      vector<pair<int, int>> theNums;
      
      sort(nums.begin(), nums.end());
      
      theNums.push_back(make_pair(nums[0], 1));
      int j = 0;
      for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i-1]) {
          theNums[j].second++;
          continue;
        }
        
        theNums.push_back(make_pair(nums[i], 1));
        j++;
      }
      
      findPermutation(theNums, thePerms, tmpPerms, nums.size());
      
      return thePerms;
    }
};