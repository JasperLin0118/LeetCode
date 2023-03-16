class Solution {
public:
    bool divideArray(vector<int>& nums) 
    {
        unordered_map<int, int> d;
        for(int i=0;i<nums.size();i++)
        {
            if(d.find(nums[i]) == d.end())
                d[nums[i]] = 1;
            else
                d[nums[i]]++;
        }
        for(auto ele : d)
        {
            if(ele.second % 2 != 0)
                return false;
        }
        return true;
    }
};