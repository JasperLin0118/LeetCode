class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) 
    {
        if(arr.size() < 3)
            return false;
        bool check = false;
        for(int i=0;i<arr.size()-2;i++)
        {
            
            int cnt = 0;
            for(int j=i;j<i+3;j++)
            {
                if(arr[j] % 2 != 0)
                    cnt++;
            }
            if(cnt == 3)
            {
                check = true;
                break;
            }
        }
        return check;
    }
};