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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        TreeNode* curr = root;
        TreeNode* curr2 = subRoot;
        queue<TreeNode*> q;
        q.push(curr);
        while(!q.empty())
        {
            TreeNode* n = q.front();
            q.pop();
            if(n->val == curr2->val)
            {
                if(check(n, curr2))
                    return true;
            }
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }
        return false;
    }
    bool check(TreeNode* root, TreeNode* subRoot)
    {
        if(root != NULL && subRoot != NULL) 
            return (root->val == subRoot->val) && (check(root->left, subRoot->left) && check(root->right, subRoot->right));
        else if(root == NULL && subRoot == NULL)
            return true;
        else
            return false;
    }
};