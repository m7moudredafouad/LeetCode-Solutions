/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> myQueue;
        
        myQueue.push(root);
        
        while(!myQueue.empty()) {
            int size = myQueue.size();
            while(size--) {
                Node * theLastNode = myQueue.front();
                myQueue.pop();
                
                if(!theLastNode) continue;                
                if(size != 0) theLastNode->next =  myQueue.front();
                
                if(theLastNode->left)   myQueue.push(theLastNode->left);
                if(theLastNode->right)   myQueue.push(theLastNode->right);
            } 
            
        }  
        
        return root;
    }
};