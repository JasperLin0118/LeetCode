class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    int countWays(vector<vector<int>>& ranges) 
    {
        if(ranges.size() == 1)
            return 2;
        sort(ranges.begin(), ranges.end(), cmp);
        int ans = 2, cnt = 0, low = ranges[0][0], high = ranges[0][1];
        for(int i=1;i<ranges.size();i++)
        {
            if(high >= ranges[i][0])
            {
                low = (ranges[i][0] < low) ? ranges[i][0] : low;
                high = (ranges[i][1] > high) ? ranges[i][1] : high;
            }
            else
            {
                high = ranges[i][1];
                low = ranges[i][0];
                cnt++;
            }
        }
        while(cnt--)
            ans = (ans * 2) % 1000000007;
        return ans;
    }
};