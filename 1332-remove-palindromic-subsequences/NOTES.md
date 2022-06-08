* Remove the **subsequence**.
* The input string only consists of letters **[a, b]**.
* That means, there are 3 situations of this problem:
1. String length == 0  return 0;
2. String is a Palindrome -> return 1;
3. Other cases, you can first remove all 'a' and then all 'b' or vice versa -> return 2;