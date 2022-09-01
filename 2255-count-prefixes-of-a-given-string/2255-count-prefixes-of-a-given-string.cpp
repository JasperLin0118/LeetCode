class Solution {
public:
    int countPrefixes(vector<string>& words, string s) 
    {
        int ans = 0;
        for(string word: words)
        {
            if(s.find(word) == 0)
                ans++;
        }
        return ans;
    }
};