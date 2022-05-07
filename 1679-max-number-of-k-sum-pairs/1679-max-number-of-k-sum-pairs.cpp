class Solution {
    unordered_map<int, bool> mymap;
    
    int bst(vector<int>& nums, int val, int start, int end) {
        if(start > end) return -1;
        int mid = (start + end) / 2;
        
        if(nums[mid] == val && mymap[mid] != true) {
            mymap[mid] = true;
            return mid;
        } else if (nums[mid] == val && mymap[mid] == true) {
            int i = bst(nums, val, start, mid - 1);
            if(i == -1) {
                return bst(nums, val, mid + 1, end);
            }
            return i;
        } else if (nums[mid] >= val) {
            return bst(nums, val, start, mid - 1);
        } else {
            return bst(nums, val, mid + 1, end);
        }
    }
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int searchingVal;
        int foundIndex;
        int size = nums.size();
        int i = size, counter = 0;
        
        while(i--) {
            if(mymap[i] == true) continue;
            searchingVal = k - nums[i];

            foundIndex = bst(nums, searchingVal, 0, i - 1);
            
            //cout << searchingVal << " : "  << foundIndex << endl;
           if(foundIndex >= 0) {
               counter++;
               mymap[i] = true;
           }     
        }
        
        
        return counter;
    }
};