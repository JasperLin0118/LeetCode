class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) 
    {
        unordered_map<int, int> d;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(key == nums[i])
            {
                if(d.find(nums[i+1]) == d.end())
                    d[nums[i+1]] = 1;
                else
                    d[nums[i+1]]++;
            }
        }
        int mx = 0, mxkey = 0;
        for(auto ele : d)
        {
            if(ele.second > mx)
            {
                mx = ele.second;
                mxkey = ele.first;
            }
        }
        return mxkey;
    }
};