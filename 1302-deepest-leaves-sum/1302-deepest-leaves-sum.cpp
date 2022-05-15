/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
      queue<TreeNode*> myQ;
      myQ.push(root);
      int sum = 0;
      
      while(!myQ.empty()) {
        int size = myQ.size();
        sum = 0; 
        
        while(size--) {
          TreeNode* last = myQ.front();
          myQ.pop();
          
          sum += last->val;
          
          if(last->left)  myQ.push(last->left);
          if(last->right)  myQ.push(last->right);
        }
        
      }
      
      return sum;
    }
};