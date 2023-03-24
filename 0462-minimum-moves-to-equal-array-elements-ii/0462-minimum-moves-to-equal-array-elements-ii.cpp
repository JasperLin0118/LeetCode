class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int median = nums[nums.size()/2];
        int cnt = 0;
        for(int i=0;i<nums.size();i++)
            cnt += (nums[i] >= median) ? nums[i] - median : median - nums[i];
        return cnt;
    }
};