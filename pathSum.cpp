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
    bool pathSum(TreeNode * root, int targetSum, int paths)
    {
        if(!root)
            return 0;
        if((!root->left) && (!root->right))
        {
            return ((paths + root->val) == targetSum);
        }
        bool ltree = pathSum(root->left, targetSum, paths+root->val);
        bool rtree = pathSum(root->right, targetSum, paths+root->val);
        return (ltree || rtree);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return (root) && (pathSum(root, targetSum,0));
    }
};
