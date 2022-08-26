class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        int total = 0;
        map<pair<int, int>, int> dict;
        for(int i=0;i<dominoes.size();i++)
        {
            pair<int, int> p = make_pair(dominoes[i][0], dominoes[i][1]);
            pair<int, int> rp = make_pair(dominoes[i][1], dominoes[i][0]);
            if(dict.find(p) != dict.end())
                dict[p]++;
            else if(dict.find(rp) != dict.end())
                dict[rp]++;
            else
                dict[p]++;
        }
        for(auto data : dict)
        {
            if(data.second > 1)
                total += (data.second - 1) * data.second / 2;
        }
        return total;
    }
};