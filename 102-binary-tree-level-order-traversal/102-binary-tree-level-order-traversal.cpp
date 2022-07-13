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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> vect;
        queue<TreeNode*> Q;
        Q.push(root);

        int index = 0;
        while(!Q.empty()) {
            int size = Q.size();
            vect.push_back({});
            
            while(size--) {
                TreeNode* tmp = Q.front();
                Q.pop();
                
                if(!tmp) continue;
                if(tmp->left) Q.push(tmp->left);
                if(tmp->right) Q.push(tmp->right);

                vect[index].push_back(tmp->val);
            }
            
            index++;
        }
        
        return vect;
    }
};