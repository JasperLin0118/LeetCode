class Solution {
public:
    string oddString(vector<string>& words) 
    {
        vector<string> diff(words.size());
        for(int i=0;i<words.size();i++)
        {
            string s = "";
            for(int j=0;j<words[i].length()-1;j++)
                s += to_string(words[i][j+1] - words[i][j]) + " ";
            diff[i] = s;
        }
        int ind = 0;
        unordered_map<string, int> d;
        for(int i=0;i<words.size();i++)
        {
            if(d.find(diff[i]) == d.end())
                d[diff[i]] = 1;
            else
                d[diff[i]]++;
        }
        string ans = "";
        for(auto ele : d)
        {
            if(ele.second == 1)
                ans = ele.first;
        }
        for(int i=0;i<words.size();i++)
        {
            if(ans == diff[i])
            {
                ind = i;
                break;
            }
        }
        return words[ind];
    }
};