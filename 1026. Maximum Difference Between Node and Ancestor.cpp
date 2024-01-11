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
    int maxdiff;
    void findmaxdif(TreeNode* root,TreeNode* child){
        if(root==NULL || child==NULL){
            return;
        }
        maxdiff=max(maxdiff,abs(root->val-child->val));
        findmaxdif(root,child->left);
        findmaxdif(root,child->right);
    }
    void pass(TreeNode* root){
        if(root==NULL){
            return;
        }
        findmaxdif(root,root->left);
        findmaxdif(root,root->right);
        pass(root->right);
        pass(root->left);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        maxdiff=-1;
        pass(root);
        return maxdiff;
    }
};
