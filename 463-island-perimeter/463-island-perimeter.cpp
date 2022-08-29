class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                    dfs(grid, visited, i, j, ans);
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& land, vector<vector<bool>>& visited, int x, int y, int& curr)
    {
        curr += 4;
        visited[x][y] = true;
        if(x - 1 >= 0 && land[x-1][y] == 1)
        {
            if(!visited[x-1][y])
                dfs(land, visited, x - 1, y, --curr);
            else
                curr--;
        }
        if(x + 1 < land.size() && land[x+1][y] == 1)
        {
            if(!visited[x+1][y])
                dfs(land, visited, x + 1, y, --curr);
            else
                curr--;
        }
        if(y - 1 >= 0 && land[x][y-1] == 1)
        {
            if(!visited[x][y-1])
                dfs(land, visited, x, y - 1, --curr);
            else
                curr--;
        }
        if(y + 1 < land[x].size() && land[x][y+1] == 1)
        {
            if(!visited[x][y+1])
                dfs(land, visited, x, y + 1, --curr);
            else
                curr--;
        }
    }
};