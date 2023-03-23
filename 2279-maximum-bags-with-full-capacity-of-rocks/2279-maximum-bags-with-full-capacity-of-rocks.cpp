class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return (a.first - a.second) < (b.first - b.second);
    }
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        vector<pair<int, int>> v(rocks.size());
        for(int i=0;i<rocks.size();i++)
            v[i] = make_pair(capacity[i], rocks[i]);
        sort(v.begin(), v.end(), cmp);
        int cnt = 0;
        for(auto ele : v)
        {
            if(additionalRocks == 0)
                return cnt;
            int curr = ele.first - ele.second;
            if(curr == 0)
                cnt++;
            else
            {
                if(curr <= additionalRocks)
                {
                    cnt++;
                    additionalRocks -= curr;
                }
            }
        }
        return cnt;
    }
};