class Solution {
public:
    int longestPalindrome(string s) 
    {
        int ans = 0, odd = 0;
        map<char, int> dict;
        for(char c: s)
            dict[c]++;
        for(auto a:dict)
        {
            ans += a.second;
            if(a.second % 2 == 1)
                odd++;
        }
        if(odd != 0)
            return ans - (odd - 1);
        else
            return ans;
    }
};