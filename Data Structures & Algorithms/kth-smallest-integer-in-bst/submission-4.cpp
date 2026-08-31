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
    //we always keep going to the left subtree at the start of the function so we can make sure to get to the abslute smallest number first before raising our nodes variable
public:
    int nodes = 0; // number of nodes we have counted as the smallest
    int answer;
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) {return answer;}

        kthSmallest(root->left, k);
        if(nodes < k) {
            nodes++;
            answer = root->val;
        } else if(nodes == k) {return answer;}

        kthSmallest(root->right, k);
        return answer;
    }
};
