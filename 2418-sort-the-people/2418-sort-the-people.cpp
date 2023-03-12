class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        map<int, string> d;
        vector<string> ans(names.size());
        for(int i=0;i<names.size();i++)
            d[heights[i]] = names[i];
        int ind = names.size()-1;
        for(auto ele : d)
            ans[ind--] = ele.second;
        return ans;
    }
};