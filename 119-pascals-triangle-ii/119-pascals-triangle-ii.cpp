class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        rowIndex++;
        vector<vector<int>> ans;
        for(int i=1;i<rowIndex+1;i++)
        {
            vector<int> v(i, 1);
            if(i == 1 || i == 2)
                ans.push_back(v);
            else
            {
                for(int j=1;j<i-1;j++)
                    v[j] = ans[i-2][j-1] + ans[i-2][j];
                ans.push_back(v);
            }
        }
        return ans[ans.size()-1];
    }
};