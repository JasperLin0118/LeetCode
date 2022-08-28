class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) 
    {
        map<int, int> zeros;
        unordered_map<int, int> cities;
        set<int> city;
        vector<int> ans(rains.size(), 1);
        for(int i=0;i<rains.size();i++)
        {
            if(rains[i] == 0)
                zeros[i] = -1;
            else
            {
                int curr_size = city.size();
                city.insert(rains[i]);
                if(city.size() > curr_size) //new city
                {
                    ans[i] = -1;
                    cities[rains[i]] = i;
                }
                else
                {
                    bool check = false;
                    for(map<int, int>::iterator data=zeros.begin();data!=zeros.end();data++)
                    {
                        if(data->first >= cities[rains[i]] && data->second == -1)
                        {
                            cities[rains[i]] = i;
                            //data->second = rains[i];
                            check = true;
                            ans[i] = -1;
                            ans[data->first] = rains[i];
                            zeros.erase(data);
                            break;
                        }
                    }
                    if(!check)
                        return vector<int>();
                }
            }
        }
        return ans;
    }
};