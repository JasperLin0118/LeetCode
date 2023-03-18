class Solution {
public:
    int countDigits(int num) 
    {
        int ans = 0, original_num = num;
        while(num != 0)
        {
            if(original_num % (num % 10) == 0)
                ans++;
            num /= 10;
        }
        return ans;
    }
};