class Solution {
public:
    int tupleSameProduct(vector<int>& nums) 
    {
        unordered_map<int, int> d;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(d.find(nums[i] * nums[j]) == d.end())
                    d[nums[i] * nums[j]] = 1;
                else
                    d[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        for(auto ele:d)
        {
            if(ele.second >= 2)
            {
                ans += (ele.second * (ele.second - 1)) / 2;
            }
        }
        return ans*8;
    }
};