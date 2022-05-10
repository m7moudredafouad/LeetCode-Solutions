class Solution {
  
  void search(vector<vector<int>> &addFoundHere, vector<int> &tempPattern, int lastAddedNumber, int k, int n) {
    if(k == 1) {
      tempPattern.push_back(n);
      
      if(n > lastAddedNumber && n < 10) {
        addFoundHere.push_back(tempPattern);
      }
      
      tempPattern.pop_back();
      return;
    }
    
    for(int i = lastAddedNumber+1; i < 10; i++) {
      tempPattern.push_back(i);
      search(addFoundHere, tempPattern, i, k-1, n-i);
      tempPattern.pop_back();
    }
  }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>> addFoundHere;
      vector<int> tempPattern;
      search(addFoundHere, tempPattern, 0, k, n);
      return addFoundHere;
    }
};