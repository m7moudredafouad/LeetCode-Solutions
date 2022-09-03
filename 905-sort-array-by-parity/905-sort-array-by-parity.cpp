/*
//  FIRST SOL
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

*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> sol(nums.size());
        int first = 0, last = nums.size() - 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 0) {
                sol[first++] = nums[i];
            } else {
                sol[last--] = nums[i];
            }
            
        }
        
        return sol;
    }
};