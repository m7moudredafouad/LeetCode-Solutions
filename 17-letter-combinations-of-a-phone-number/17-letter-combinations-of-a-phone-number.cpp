class Solution {
  string getTheLettersOfNumber(char x) {
    switch(x) {
      case '2':
        return "abc";
      case '3':
        return "def";
      case '4':
        return "ghi";
      case '5':
        return "jkl";
      case '6':
        return "mno";
      case '7':
        return "pqrs";
      case '8':
        return "tuv";
      case '9':
        return "wxyz";
      default:
        return "";
    }
  }
public:
    vector<string> letterCombinations(string digits) {
      int patternsLen = 1;
      for(int i = 0; i < digits.length(); i++) {
        patternsLen *= getTheLettersOfNumber(digits[i]).length();
      }
      if(digits.length() == 0) patternsLen = 0;
      vector<string> s(patternsLen);
      
      int patternIndex;
      string curDigitStr;
      int curDigitLen;
      int fillSize = patternsLen;
      
      for(int i = 0; i < digits.length(); i++) {
        patternIndex = 0;
        curDigitStr = getTheLettersOfNumber(digits[i]);
        curDigitLen = curDigitStr.length();
        fillSize = fillSize / curDigitLen;
                
        while(patternIndex < patternsLen) {
          for(int j = 0; j < curDigitLen; j++) {
            for(int k = 0; k < fillSize; k++) {
              s[patternIndex++] += curDigitStr[j];
            }
          }
        }
        
      }
      
      return s;
    }
};