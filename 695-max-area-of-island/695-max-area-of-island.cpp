class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    int curr = 0;
                    dfs(grid, visited, i, j, curr);
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& land, vector<vector<bool>>& visited, int x, int y, int& curr)
    {
        if(land[x][y] == 1)
        {
            curr++;
            visited[x][y] = true;
        }
        else
            return;
        if(x - 1 >= 0 && !visited[x-1][y])
            dfs(land, visited, x - 1, y, curr);
        if(x + 1 < land.size() && !visited[x+1][y])
            dfs(land, visited, x + 1, y, curr);
        if(y - 1 >= 0 && !visited[x][y-1])
            dfs(land, visited, x, y - 1, curr);
        if(y + 1 < land[x].size() && !visited[x][y+1])
            dfs(land, visited, x, y + 1, curr);
    }
};