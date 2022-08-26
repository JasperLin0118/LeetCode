class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        vector<vector<int>> adj_mat(bombs.size(), vector<int>(bombs.size(), 0));
        for(int i=0;i<bombs.size();i++)
        {
            for(int j=0;j<bombs.size();j++)
            {
                if(i == j)
                    continue;
                double dist = sqrt(pow(bombs[i][1] - bombs[j][1], 2) + pow(bombs[i][0] - bombs[j][0], 2));
                if(dist <= bombs[i][2])
                    adj_mat[i][j] = 1;
            }
        }
        int ans = 0;
        for(int i=0;i<bombs.size();i++)
        {
            vector<bool> visit(bombs.size(), false);
            int cnt = 1;
            dfs(adj_mat, i, visit, cnt);
            ans = max(cnt, ans);
        }
        return ans;
    }
    void dfs(vector<vector<int>> &graph, int v, vector<bool> &visit, int &cnt)
    {
        visit[v] = true;
        for(int i=0;i<graph.size();i++)
        {
            if(graph[v][i] == 1 && !visit[i]) 
                dfs(graph, i, visit, ++cnt);
        }
    }
};