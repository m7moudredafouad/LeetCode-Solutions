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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *> q;
        vector<double> av;
        
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            int i = size;
            long  sum = 0;
            while(i--) {
                TreeNode * tmp = q.front();
                q.pop();
                sum += tmp->val;
                
                if(tmp->left)   q.push(tmp->left);
                if(tmp->right)   q.push(tmp->right);
            }
            
            av.push_back( sum / (double)size);
        }
        
        return av;
        
        
    }
};