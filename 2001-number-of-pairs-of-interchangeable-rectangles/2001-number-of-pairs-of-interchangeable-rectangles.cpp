class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) 
    {
        long long ans = 0;
        map<double, long long> dict;
        for(int i=0;i<rectangles.size();i++)
        {
            double ratio = (double)rectangles[i][0] / (double)rectangles[i][1];
            if(dict.find(ratio) != dict.end())
                dict[ratio]++;
            else 
                dict[ratio] = 1;
        }
        for(auto& s : dict) 
            ans += (s.second)*(s.second-1) / 2;
        return ans;
    }
};