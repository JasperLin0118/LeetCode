class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adjlist(n);
        for(auto edge:edges)
        {
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }
        long long ans = 0;
        vector<vector<int>> components;
        vector<bool> visited(n, false);
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            if(!visited[i]);
                dfs(visited, adjlist, v, i);
            if(v.size() != 0)
                components.push_back(v);
        }
        for(auto data:components)
            ans += data.size() * (n - data.size());
        return ans / 2;
    }
    void dfs(vector<bool>& visited, vector<vector<int>>& adjlist, vector<int>& v, int i)
    {
        if(visited[i])
            return;
        visited[i] = true;
        v.push_back(i);
        for(int a:adjlist[i])
        {
            if(!visited[a])
                dfs(visited, adjlist, v, a);
        }
    }
};