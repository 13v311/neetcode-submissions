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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) {return nullptr;}

        invertTree(root->left);
        invertTree(root->right);

        if(root->left != nullptr && root->right != nullptr) {
            TreeNode* ogLeft = root->left;
            root->left = root->right;
            root->right = ogLeft;
        } else if(root->right != nullptr) {
            root->left = root->right;
            root->right = nullptr;
        } else {
            root->right = root->left;
            root->left = nullptr;
        }
        return root;
    }
};
