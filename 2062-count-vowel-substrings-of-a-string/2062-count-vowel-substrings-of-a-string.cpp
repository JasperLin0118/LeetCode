class Solution {
public:
    int countVowelSubstrings(string word) 
    {
        unordered_map<string, int> d;
        string curr = "";
        bool a = false, e = false, i = false, o = false, u = false;
        for(int j=0;j<word.length();j++)
        {
            for(int k=j;k<word.length();k++)
            {
                if(word[k] == 'a')
                {
                    a = true;
                    curr += word[k];
                }
                else if(word[k] == 'e')
                {
                    e = true;
                    curr += word[k];
                }
                else if(word[k] == 'i')
                {
                    i = true;
                    curr += word[k];
                }
                else if(word[k] == 'o')
                {
                    o = true;
                    curr += word[k];
                }
                else if(word[k] == 'u')
                {
                    u = true;
                    curr += word[k];
                }
                else
                    break;
                if(a && e && i && o && u)
                {
                    if(d.find(curr) == d.end())
                        d[curr] = 1;
                    else
                        d[curr]++;
                }
            }
            a=false;
            e=false;
            i=false;
            o=false;
            u=false;
            curr = "";
        }
        int cnt = 0;
        for(auto ele:d)
            cnt += ele.second;
        return cnt;
    }
};