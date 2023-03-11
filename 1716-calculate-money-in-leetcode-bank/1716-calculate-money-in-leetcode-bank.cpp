class Solution {
public:
    int totalMoney(int n) 
    {
        int total = 0, week = 0, day = 1;
        while(n--)
        {
            total += week + day;
            if(day == 7)
            {
                day = 1;
                week++;
            }
            else
                day++;
        }
        return total;
    }
};