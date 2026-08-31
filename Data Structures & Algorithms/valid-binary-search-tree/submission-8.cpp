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
//originally i was just checking one value, but i actually need ot check a range of values (minimum to maximum) because a node later in the tree can pass the rule of its parent but not an earlier parent
    bool validBST_helper(TreeNode* root, int min, int max) {
        if(root == nullptr) {return true;}


        if(root->val <= min || root->val >= max) {return false;} 

        return validBST_helper(root->left, min, root->val) && validBST_helper(root->right, root->val, max);
        
    }

    bool isValidBST(TreeNode* root) {
        if(root == nullptr) {return true;}

        return validBST_helper(root, -1000000000, 1000000000);
    }
};
