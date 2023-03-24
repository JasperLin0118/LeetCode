class Solution {
public:
    int minPartitions(string n) 
    {
        int mx = 0;
        for(int i=0;i<n.length();i++)
        {
            if(n[i] - '0' > mx)
                mx = n[i] - '0';
        }
        return mx;
    }
};