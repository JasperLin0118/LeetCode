class Solution {
public:
    int countPoints(string rings) 
    {
        vector<bool> r(10, false);
        vector<bool> g(10, false);
        vector<bool> b(10, false);
        for(int i=0;i<rings.length();i+=2)
        {
            if(rings[i] == 'R' && r[rings[i+1] - '0'] == false)
                r[rings[i+1] - '0'] = true;
            else if(rings[i] == 'G' && g[rings[i+1] - '0'] == false)
                g[rings[i+1] - '0'] = true;
            else if(rings[i] == 'B' && b[rings[i+1] - '0'] == false)
                b[rings[i+1] - '0'] = true;
            
        }
        int ans = 0;
        for(int i=0;i<10;i++)
        {
            if(r[i] && g[i] && b[i])
                ans++;
        }
        return ans;
    }
};