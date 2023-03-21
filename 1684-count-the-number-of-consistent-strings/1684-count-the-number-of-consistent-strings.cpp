class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        int ans = 0;
        for(int i=0;i<words.size();i++)
        {
            bool flag = true;
            for(int j=0;j<words[i].size();j++)
            {
                if(allowed.find(words[i][j]) == string::npos)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans++;
        }
        return ans;
    }
};