class Solution {
    int bst(vector<int>& nums, int target, int start, int end) {
        if(start > end) return -1;
        int mid = (start + end) / 2;
        
        if(nums[mid] == target) return mid;
        if(nums[mid] > target) return bst(nums, target, start, mid - 1);
        if(nums[mid] < target) return bst(nums, target, mid + 1, end);
        
        return -1;
    }
    public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> found(2);
        found[0] = found[1] = bst(nums, target, 0, nums.size() - 1);
        
        while(found[0] > 0 && nums[found[0] - 1 ] == target) found[0]--;
        while(found[1] < nums.size()-1 && nums[found[1] + 1 ] == target) found[1]++;
        
        return found;
    }
};