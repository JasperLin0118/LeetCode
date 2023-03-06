class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<vector<int>> adjlist(n, vector<int>());
        for(int i=0;i<edges.size();i++)
        {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n);
        stack<int> s;
        s.push(source);
        visited[source] = true;
        while(!s.empty())
        {
            int curr = s.top();
            visited[curr] = true;
            if(curr == destination)
                return true;
            s.pop();
            for(int i=0;i<adjlist[curr].size();i++)
            {
                if(visited[adjlist[curr][i]] == false)
                    s.push(adjlist[curr][i]);
            }
        }
        return false;
    }
};