class Solution {
public:
    bool digitCount(string num) 
    {
        unordered_map<int, int> d;
        vector<int> v(num.length());
        for(int i=0;i<num.length();i++)
        {
            v[i] = num[i] - '0';
            if(d.find(num[i] - '0') == d.end())
                d[num[i] - '0'] = 1;
            else
                d[num[i] - '0']++;
        }
        for(auto ele : d)
        {
            if(ele.first >= num.length() || v[ele.first] != ele.second)
                return false;
        }
        return true;
    }
};