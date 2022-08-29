class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int ans = 0;
        vector<bool> visited(isConnected.size(), false);
        for(int i=0;i<isConnected.size();i++)
        {
            if(!visited[i])
            {
                ans++;
                dfs(isConnected, visited, i);
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& mat, vector<bool>& visited, int v)
    {
        visited[v] = true;
        for(int i=0;i<mat.size();i++)
        {
            if(!visited[i] && mat[v][i] == 1)
                dfs(mat, visited, i);
        }
    }
};