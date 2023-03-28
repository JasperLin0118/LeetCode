class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        if(nums.size() == 1 && nums[0] == target)
            return 0;
        else if(nums.size() == 1 && nums[0] != target)
            return -1;
        int l = 0, r = nums.size()-1, mid;
        while(l <= r)
        {
            mid = (l + r) / 2;
            if(nums[mid] < target)
                l = mid + 1;
            else if(nums[mid] > target)
                r = mid - 1;
            else
                return mid;
        }
        if(nums[l] == target)
            return l;
        else 
            return -1;
    }
};