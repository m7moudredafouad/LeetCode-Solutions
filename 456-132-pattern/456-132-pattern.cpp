class Solution {
    bool findThePattern(vector<int>& nums, int start, int mid, int end) {
        if(start >= mid || mid >= end || start >= end) return false;
        
        if(end >= nums.size()) return false;
        
        if(nums[start] < nums[mid] &&
           nums[mid] > nums[end] &&
           nums[start] < nums[end]) return true;
        
        return (findThePattern(nums, start+1, mid, end) ||
                findThePattern(nums, start, mid+1, end) ||
                findThePattern(nums, start, mid, end+1)  );
    }
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> myStack;
        int thirdVal = INT_MIN;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < thirdVal) return true;
            
            while(!myStack.empty() && nums[i] > myStack.top()) {
                thirdVal = myStack.top();
                myStack.pop();
            }
            
            myStack.push(nums[i]);
        }
        
        return false;
    }
};