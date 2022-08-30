class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans;
        for(int i=1;i<numRows+1;i++)
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
        return ans;
    }
};