class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        dfs(image, visited, sr, sc, color, image[sr][sc]);
        return image;
    }
    void dfs(vector<vector<int>>& image, vector<vector<bool>>& visited, int x, int y, int color, int originalcolor)
    {
        visited[x][y] = true;
        image[x][y] = color;
        if((x - 1 >= 0 && !visited[x-1][y]) && image[x-1][y] == originalcolor)
            dfs(image, visited, x - 1, y, color, originalcolor);
        if((x + 1 < image.size() && !visited[x+1][y]) && image[x+1][y] == originalcolor)
            dfs(image, visited, x + 1, y, color, originalcolor);
        if((y - 1 >= 0 && !visited[x][y-1]) && image[x][y-1] == originalcolor)
            dfs(image, visited, x, y - 1, color, originalcolor);
        if((y + 1 < image[x].size() && !visited[x][y+1]) && image[x][y+1] == originalcolor)
            dfs(image, visited, x, y + 1, color, originalcolor);
    }
};