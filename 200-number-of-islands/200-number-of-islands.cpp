class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& land, vector<vector<bool>>& visited, int x, int y)
    {
        if(land[x][y] == '1')
            visited[x][y] = true;
        else
            return;
        if(x - 1 >= 0 && !visited[x-1][y])
            dfs(land, visited, x - 1, y);
        if(x + 1 < land.size() && !visited[x+1][y])
            dfs(land, visited, x + 1, y);
        if(y - 1 >= 0 && !visited[x][y-1])
            dfs(land, visited, x, y - 1);
        if(y + 1 < land[x].size() && !visited[x][y+1])
            dfs(land, visited, x, y + 1);
    }
};