class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> addHere;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int l = i+1, r = nums.size()-1, sum = nums[i];
            
            while(l < r) {
                int threeSum = sum + nums[l] + nums[r];
                if(threeSum > 0) {
                    r--;
                    while(nums[r] == nums[r+1] && l < r) r--;
                }
                else if(threeSum < 0) {
                    l++;
                    while(nums[l] == nums[l-1] && l < r) l++;
                } else {
                    addHere.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while(nums[l] == nums[l-1] && l < r) l++;
                }
            }
        }
        
        return addHere;
        
    }
};