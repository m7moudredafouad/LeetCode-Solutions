class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        signed char sign1 = 1, sign2 = -1;
        int secondLastAdded = 0;
        int size1 = 1, size2 = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            if(sign1 * (nums[i] - nums[i - 1]) > 0) {
                size1++;
                sign1 *= -1;
            }
            
            if(sign2 * (nums[i] - nums[i - 1]) > 0) {
                size2++;
                sign2 *= -1;
            }
        }
        
        return max(size1, size2);
    }
};