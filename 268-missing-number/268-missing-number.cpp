class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int theFullSum = 0, theArrSum = 0, i;
        for(i = 0; i < nums.size(); i++) {
            theFullSum += i;
            theArrSum += nums[i];
        }
        theFullSum += i;
        
        return theFullSum - theArrSum;
        
    }
};