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
    int nodes = 0;
    int goodNodes_helper(TreeNode* root, int value) {
        if(root == nullptr) {return 0;}
        if(root->val >= value) {
            nodes++;
            goodNodes_helper(root->left, root->val);
            goodNodes_helper(root->right, root->val);
        } else {
            goodNodes_helper(root->left, value);
            goodNodes_helper(root->right, value);
        }
        return nodes;
    }

    int goodNodes(TreeNode* root) {
        if(root == nullptr) {return 0;} else {
            nodes++;
            goodNodes_helper(root->left, root->val);
            goodNodes_helper(root->right, root->val);
            return nodes;
        }

    }
};
