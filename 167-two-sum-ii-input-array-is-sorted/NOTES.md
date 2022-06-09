One Sol
```
class Solution {
int binarySearch(vector<int>& numbers, int start, int end, int target) {
if(start > end) return -1;
int mid = (start + end) / 2;
if(numbers[mid] > target) {
return binarySearch(numbers, start, mid-1, target);
} else if(numbers[mid] < target) {
return binarySearch(numbers, mid+1, end, target);
} else {
return mid;
}
}
public:
vector<int> twoSum(vector<int>& numbers, int target) {
vector<int> sol(2);
int binaryResult = -1;
for(int i = 0; i < numbers.size(); ++i) {
binaryResult = binarySearch(numbers, i+1, numbers.size()-1, target - numbers[i]);
if(binaryResult > -1) {
sol[0] = i+1;
sol[1] = binaryResult+1;
}
}
return sol;
}
};
```