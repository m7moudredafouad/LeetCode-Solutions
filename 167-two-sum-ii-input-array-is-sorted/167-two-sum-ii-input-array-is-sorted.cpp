class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> sol(2);
        
        while(left < right) {
            if(numbers[left] + numbers[right] > target) {
                right--;
            } else if(numbers[left] + numbers[right] < target) {
                left++;
            } else {
                sol[0] = left+1;
                sol[1] = right+1;
                break;
            }
        }
        return sol;
    }
};