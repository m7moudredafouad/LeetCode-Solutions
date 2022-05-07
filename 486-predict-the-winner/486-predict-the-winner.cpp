class Solution {
    int max(int a, int b) {return a > b ? a : b;}
    
    int predict(vector<int>& nums, int start, int end, int turn) {
        if(start == end) return turn * nums[start];

        int p1 = nums[start] + turn * predict(nums, start + 1, end, -turn);
        int p2 = nums[end] + turn * predict(nums, start, end - 1, -turn);
        
        return turn * max(p1, p2);
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        return predict(nums, 0, nums.size() - 1, 1) >= 0;
    }
};