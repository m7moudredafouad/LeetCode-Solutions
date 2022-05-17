/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> myQueue;
        
        myQueue.push(cloned);
        TreeNode * found = nullptr;
        int isFound = false;
        
        while(!myQueue.empty()) {
            int size = myQueue.size();
            
            while(size--) {
                found = myQueue.front();
                myQueue.pop();
                
                if(found->val == target->val) {
                    isFound = true;
                    if(found->left) {
                        isFound |= target->left && (target->left->val == found->left->val);
                    } else {
                        isFound |= target->left == nullptr;
                    }
                    
                    if(found->right) {
                        isFound |= target->right && (target->right->val == found->right->val);
                    } else {
                        isFound |= target->right == nullptr;
                    }
                    
                    if(isFound) return found;
                    
                }
                
                if(found->left) myQueue.push(found->left);
                if(found->right) myQueue.push(found->right);
            }
            
            
        }
        
        return found;
    }
};