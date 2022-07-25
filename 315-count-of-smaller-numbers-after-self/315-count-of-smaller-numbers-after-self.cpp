class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
      int size = nums.size();
      
      vector<pair<int, int> > thePairs(size);
      
      for (int i = 0; i < size; i++){
        thePairs[i] = make_pair(nums[i], i);          
      }
      
      vector<int> counter(nums.size(), 0);
      merge(counter, thePairs, 0, size-1);
      // for (int i = 0; i < size; i++){
      //   cout << thePairs[i].first  << endl;
      // }
      return counter;
    }
  
private:
  void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
  }
  void merge(vector<int> &counter, vector<pair<int, int>> &toSort, int start, int end) {
    if(start >= end) return;
    int mid = (end + start) / 2;
    merge(counter, toSort, start, mid);
    merge(counter, toSort, mid +1, end);
    sortMerge(counter, toSort, start, mid, end);
  }
  
  void sortMerge(vector<int> &counter, vector<pair<int, int>> &toSort, int start, int mid, int end){
    vector<pair<int, int>> tmp(end - start + 1);
    
    int index_first = start, index_second = mid+1, j = 0;
    // cout << index_first << " : " << index_second << " : " << index_second << endl;
    // cout << toSort[index_first].first << endl;
    int count = 0;
    
    while(index_first <= mid && index_second <= end) {
      
      if(toSort[index_first].first <= toSort[index_second].first) {
        counter[toSort[index_first].second] += count;
        tmp[j] = toSort[index_first++];
      } else {
        count ++;
        tmp[j] = toSort[index_second++];
      }
      j++;
    }
    
    while(index_first <= mid) {
      counter[toSort[index_first].second] += count;
      tmp[j++] = toSort[index_first++];
    }
    
    while(index_second <= end) {
      tmp[j++] = toSort[index_second++];
    }
    
    for(int i = 0; i < tmp.size(); i++) {
      toSort[i+start] = tmp[i];
    }
    
  }
};