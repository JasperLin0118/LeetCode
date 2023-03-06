class Solution {
public:
    int passThePillow(int n, int time) 
    {
        int row = time / (n-1), remainder = time % (n-1);
        if(row % 2 == 0)
        {
            return remainder+1;
        }
        else 
        {
            return n - remainder;
        }
    }
};