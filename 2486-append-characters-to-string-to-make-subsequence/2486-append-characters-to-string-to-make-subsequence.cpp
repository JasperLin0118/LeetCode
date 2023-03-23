class Solution {
public:
    int appendCharacters(string s, string t) 
    {
        if(s.length() >= t.length() && s.find(t) != string::npos)
            return 0;
        int prefix = 0, ind = 0, ind_s = 0;
        while(ind != t.length())
        {
            int curr = prefix;
            for(int i=ind_s;i<s.length();i++)
            {
                if(t[ind] == s[i])
                {
                    prefix++;
                    ind_s = i + 1;
                    break;
                }
            }
            if(curr == prefix)
                break;
            ind++;
        }
        return t.length() - prefix;
    }
};