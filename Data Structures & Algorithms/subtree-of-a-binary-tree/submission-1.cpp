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
    bool subtree_helper(TreeNode* root, TreeNode* subRoot) {
       if(subRoot == nullptr && root == nullptr) {return true;} 
       else if(subRoot == nullptr || root == nullptr) {return false;}

       if(root->val != subRoot->val) {return false;}
       return subtree_helper(root->left, subRoot->left) && subtree_helper(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) {return true;} 
        else if(root == nullptr) {return false;}
        if(root->val == subRoot->val) {
            if(!subtree_helper(root, subRoot)) {
                return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
            } return true;
        } 

        else {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
    }
};
