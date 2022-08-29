class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) 
    {
        vector<int> ans(s.size(), 0);
        for(int i=0;i<s.size();i++)
        {
            int x = startPos[0], y = startPos[1];
            for(int j=i;j<s.size();j++)
            {
                if(s[j] == 'R')
                    y++;
                else if(s[j] == 'L')
                    y--;
                else if(s[j] == 'U')
                    x--;
                else if(s[j] == 'D')
                    x++;
                if((x >= 0 && x < n) && (y >= 0 && y < n))
                    ans[i]++;
                else
                    break;
            }
        }
        return ans;
    }
};