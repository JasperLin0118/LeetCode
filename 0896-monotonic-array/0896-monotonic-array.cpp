class Solution {
public:
    bool isMonotonic(vector<int>& nums) 
    {
        bool is_inc = true, is_dec = true;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(is_inc && nums[i] > nums[i+1])
                is_inc = false;
            if(is_dec && nums[i] < nums[i+1])
                is_dec = false;
        }
        return (is_inc || is_dec);
    }
};