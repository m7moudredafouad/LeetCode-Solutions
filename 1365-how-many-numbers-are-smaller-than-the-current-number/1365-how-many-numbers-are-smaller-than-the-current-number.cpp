class Solution {

public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> map(101);
        vector<int> counter(nums.size());
        
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        
        for(int i = 1; i < 100; i++) {
            map[i] += map[i - 1];
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                counter[i] = 0;
                continue;
            }
            counter[i] = map[nums[i] - 1];
        }
        
        return counter;
    }
};