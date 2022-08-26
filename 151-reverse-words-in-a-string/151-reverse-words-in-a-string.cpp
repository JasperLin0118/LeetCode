class Solution {
public:
    string reverseWords(string s) 
    {
        s += " ";
        vector<string> v;
        int begin = 0, end = s.find(" ");
        while (end != string::npos) 
        {
            if (end - begin != 0) 
                v.push_back(s.substr(begin, end-begin)); 
            begin = end + 1;
            end = s.find(" ", begin);
        }
        string ans = "";
        for(int i=v.size()-1;i>=0;i--)
        {
            if(i == 0)
                ans += v[i];
            else
                ans += v[i] + " ";
        }
        return ans;
    }
};