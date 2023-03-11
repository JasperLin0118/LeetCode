class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        sort(nums.begin(), nums.end());
        int high = nums[nums.size()-1], low = 1, mid;
        while(low <= high)
        {
            int cnt = 0;
            mid = (high + low) / 2;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i] <= mid)
                    cnt++;
                else
                {
                    cnt += nums[i] / mid;
                    if(nums[i] % mid != 0)
                        cnt++;
                }
            }
            if(cnt <= threshold) //move left
                high = mid - 1;
            else //move right
                low = mid + 1;
        }
        return low;
    }
};