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
private:
  TreeNode* buildTree_2(vector<int>& preorder, vector<int>& inorder, int & rootIndex, int start, int end) {
    if(start > end) return nullptr;
    int foundIndex = start;
    
    while(preorder[rootIndex] != inorder[foundIndex]) foundIndex++;
    
    rootIndex++;
    
    TreeNode * newNode = new TreeNode(inorder[foundIndex]);
    newNode->left = buildTree_2(preorder, inorder, rootIndex, start, foundIndex - 1);
    newNode->right = buildTree_2(preorder, inorder, rootIndex, foundIndex + 1, end);

    return newNode;
  }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int rootIndex = 0;
      
      return buildTree_2(preorder, inorder, rootIndex, 0, preorder.size()-1);
    }
};

