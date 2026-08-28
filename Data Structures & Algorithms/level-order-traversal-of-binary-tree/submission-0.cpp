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
//the key is to use a queue, and each time ur on a node, u push its left and right nodes to the queue. so then, each iteration ur at a new level
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if(root == nullptr) {return levels;}
        int currLevel = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int levelSize = q.size();
            levels.push_back({});
            for(size_t i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front();
                levels[currLevel].push_back(temp->val);

                if(temp->left != nullptr) {q.push(temp->left);}
                if(temp->right != nullptr) {q.push(temp->right);}

                q.pop();

            }
            currLevel++;
        }
        return levels;
    }
};
