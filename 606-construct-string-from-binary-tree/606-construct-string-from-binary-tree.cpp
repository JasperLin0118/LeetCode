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
    string preorder(TreeNode* curr, string ans)
    {
        bool check = true;
        ans += to_string(curr->val);
        if(curr->left)
        {
            ans += "(";
            ans = preorder(curr->left, ans);
            ans += ")";
        }
        else
            check = false;
        if(curr->right)
        {
            if(!check)
                ans += "()";
            ans += "(";
            ans = preorder(curr->right, ans);
            ans += ")";
        }
        return ans;
    }
    string tree2str(TreeNode* root) 
    {
        string ans = "";
        TreeNode* node = root;
        return preorder(node, ans);
    }
};