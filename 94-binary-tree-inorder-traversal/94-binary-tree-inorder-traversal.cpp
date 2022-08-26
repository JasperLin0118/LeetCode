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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode* current = root;
        while(!s.empty() || current != NULL)
        {
            if(current != NULL) //when you have route to keep going
            {
                s.push(current);
                current = current->left;
            }
            else //when it's deadend
            {
                current = s.top();
                s.pop();
                v.push_back(current->val);
                current = current->right;
            }
        }
        return v;
    }
};