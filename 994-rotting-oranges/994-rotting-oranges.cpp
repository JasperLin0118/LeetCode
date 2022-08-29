class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<tuple<int, int, int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j] == 2)
                    q.push(make_tuple(i, j, 0));
            }
        }
        int total_min = 0;
        while(!q.empty())
        {
            tuple<int, int, int> curr = q.front();
            q.pop();
            int x = get<0>(curr), y = get<1>(curr), min = get<2>(curr);
            if(visited[x][y])
                continue;
            total_min = max(total_min, min);
            grid[x][y] = 2;
            visited[x][y] = true;
            if((x - 1 >= 0 && grid[x-1][y] == 1) && !visited[x-1][y])
                q.push(make_tuple(x-1, y, min+1));
            if((x + 1 < grid.size() && grid[x+1][y] == 1) && !visited[x+1][y])
                q.push(make_tuple(x+1, y, min+1));
            if((y - 1 >= 0 && grid[x][y-1] == 1) && !visited[x][y-1])
                q.push(make_tuple(x, y-1, min+1));
            if((y + 1 < grid[x].size() && grid[x][y+1] == 1) && !visited[x][y+1])
                q.push(make_tuple(x, y+1, min+1));
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return total_min;
    }
};