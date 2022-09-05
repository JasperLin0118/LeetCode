class Solution {
public:
    int minimumNumbers(int num, int k) 
    {
        if(num == 0)
            return 0;
        vector<int> tens(10, -1);
        for(int i=1;i<=10;i++)
        {
            if(tens[(k * i) % 10] != -1)
                tens[(k * i) % 10] = min(tens[(k * i) % 10], i);
            else
                tens[(k * i) % 10] = i;
        }
        if(tens[num % 10] == -1 || tens[num % 10]*k > num)
            return -1;
        else
            return tens[num % 10];
    }  
};