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
//breadth first search seems to use queue
    vector<int> rightSideView(TreeNode* root) {
     vector<int> nodes;
     if(root == nullptr) {return nodes;}

     nodes.push_back(root->val);  
     queue<TreeNode*> q;
     if(root->left != nullptr) {q.push(root->left);}
     if(root->right != nullptr) {q.push(root->right);}

     while(!q.empty()) {
        int levelSize = q.size();

        for(size_t i = 0; i < levelSize; i++) {
            TreeNode* curr = q.front();
            if(i == levelSize-1) {
                nodes.push_back(curr->val);
            }

            if(curr->left != nullptr) {q.push(curr->left);}
            if(curr->right != nullptr) {q.push(curr->right);}
            q.pop();
        }


     }
    return nodes;
    }

};
