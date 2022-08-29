class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        vector<vector<bool>> visited(grid1.size(), vector<bool>(grid1[0].size(), false));
        int ans = 0;
        for(int i=0;i<grid1.size();i++)
        {
            for(int j=0;j<grid1[i].size();j++)
            {
                if(!visited[i][j] && grid2[i][j] == 1)
                {
                    bool check = true;
                    dfs(grid1, grid2, visited, i, j, check);
                    if(check)
                        ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& land, vector<vector<bool>>& visited, int x, int y, bool& check)
    {
        visited[x][y] = true;
        if(land[x][y] == 1 && grid1[x][y] == 0)
            check = false;
        if((x - 1 >= 0 && !visited[x-1][y]) && land[x-1][y] == 1)
            dfs(grid1, land, visited, x - 1, y, check);
        if((x + 1 < land.size() && !visited[x+1][y]) && land[x+1][y] == 1)
            dfs(grid1, land, visited, x + 1, y, check);
        if((y - 1 >= 0 && !visited[x][y-1]) && land[x][y-1] == 1)
            dfs(grid1, land, visited, x, y - 1, check);
        if((y + 1 < land[x].size() && !visited[x][y+1]) && land[x][y+1] == 1)
            dfs(grid1, land, visited, x, y + 1, check);
    }
};