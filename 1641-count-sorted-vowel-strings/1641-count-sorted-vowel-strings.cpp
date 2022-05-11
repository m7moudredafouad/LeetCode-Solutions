class Solution {
private:
  string vowels = "aeiou";
  void search(int &count, int remainingChars, char lastCharIndex) {
    if(remainingChars == 0) {
      count++;
      return;
    }
    
    for(int i = lastCharIndex; i < 5; i++) {
      //if(vowels[i] >= lastChar) {
        search(count, remainingChars-1, i);
      //}
    }
  }
  
public:
    int countVowelStrings(int n) {
      int count = 0;
      search(count, n, 0);
      return count;
    }
};