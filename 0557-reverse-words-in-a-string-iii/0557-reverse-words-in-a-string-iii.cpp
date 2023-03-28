class Solution {
public:
    string reverseWords(string s) 
    {
        if(s.length() == 1)
            return s;
        s += " ";
        string ans = "";
        int blank = 0;
        while(blank < s.length()-1)
        {
            int start = blank;
            for(int i=start+1;i<s.length();i++)
            {
                if(s[i] == ' ')
                {
                    blank = i;
                    break;
                }
            }
            for(int i=blank-1;i>=start;i--)
                ans += s[i];
            if(start == 0)
                ans += ' ';
        }
        return ans.substr(0, ans.length()-1);
    }
};