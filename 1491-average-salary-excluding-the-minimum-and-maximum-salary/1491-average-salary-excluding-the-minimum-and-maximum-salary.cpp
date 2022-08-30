class Solution {
public:
    double average(vector<int>& salary) 
    {
        double sm = 0, mx = 0, mn = INT_MAX;
        for(int i=0;i<salary.size();i++)
        {
            sm += salary[i];
            if(salary[i] > mx)
                mx = salary[i];
            if(salary[i] < mn)
                mn = salary[i];
        }
        cout << mx << " " << mn << " " << sm << endl;
        return (sm - mn - mx) / (salary.size()-2);
    }
};