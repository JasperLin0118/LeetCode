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
    void dfs(TreeNode* curr, int currcnt, vector<long long> &ans, int &mxlevel)
    {
        mxlevel = max(currcnt, mxlevel);
        ans[currcnt] += curr->val;
        if(curr->left)
        {
            dfs(curr->left, currcnt+1, ans, mxlevel);
        }
        if(curr->right)
        {
            dfs(curr->right, currcnt+1, ans, mxlevel);
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        vector<long long> ans(100005);
        int mxlevel = 1;
        TreeNode* head = root;
        dfs(head, 1, ans, mxlevel);
        sort(ans.begin(), ans.end());
        // for(int i=0;i<10;i++)
        //     cout << ans[ans.size()-i-1] << " ";
        // cout << endl;
        cout << mxlevel << endl;
        if(mxlevel < k)
            return -1;
        return ans[ans.size() - k];
    }
};