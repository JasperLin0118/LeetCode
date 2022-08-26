class Solution {
public:
    int findMiddleIndex(vector<int>& nums) 
    {
        int middleindex = -1;
        int leftsum = 0, rightsum = 0;
        for(int i=1;i<nums.size();i++)
            rightsum += nums[i];
        if(leftsum == rightsum)
            return 0;
        for(int i=1;i<nums.size();i++)
        {
            leftsum += nums[i-1];
            rightsum -= nums[i];
            if(leftsum == rightsum)
            {
                middleindex = i;
                break;
            }
        }
        return middleindex;
    }
};