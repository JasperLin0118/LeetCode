class Solution {
public:
    int countAsterisks(string s) 
    {
        int ans = 0;
        bool bar = false;
        for(int i=0;i<s.length();i++)
        {
            if(bar == false && s[i] == '*')
                ans++;
            else if(s[i] == '|' && bar == false)
                bar = true;
            else if(s[i] == '|' && bar == true)
                bar = false;
        }
        return ans;
    }
};