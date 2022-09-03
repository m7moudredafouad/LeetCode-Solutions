class Solution {
    void swap(int *x, int* y) {
        int tmp = *x;
        *x = *y;
        *y = tmp;
    }
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 0) continue;
            
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[j] % 2 == 0) {
                    swap(&nums[i], &nums[j]);
                    break;
                }
            }
        }
        
        return nums;
    }
};