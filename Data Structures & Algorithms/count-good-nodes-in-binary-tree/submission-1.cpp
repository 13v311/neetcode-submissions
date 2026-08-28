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
//ayyy this is the 1st one i did by myself for bst mediums just by looking at the hints; i knew that it would be DFS just not sure how to keep track of what we've already seen, but since it is a BST we only need to keep track of the highest value we've seen so far in our current path, which will get updated if we ever reach a node with a value higher than that!
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
