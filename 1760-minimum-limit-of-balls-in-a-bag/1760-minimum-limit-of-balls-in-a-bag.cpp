class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        sort(nums.begin(), nums.end());
        int high = nums[nums.size()-1], low = 1, mid;
        while(low <= high)
        {
            int total = 0;
            mid = (high+low)/2;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i] > mid)
                    total += (nums[i]-1) / mid;
            }
            cout << mid << " " << total << endl;
            // if(total == maxOperations)
            //     break;
            if(total <= maxOperations) //go left
                high = mid - 1;
            else// if(total > maxOperations) //go right
                low = mid + 1;
        }
        return low;
    }
};