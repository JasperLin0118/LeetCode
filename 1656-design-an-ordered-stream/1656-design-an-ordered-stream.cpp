class OrderedStream {
public:
    int current_id;
    map<int, string> d;
    OrderedStream(int n) 
    {
        current_id = 1;
    }
    
    vector<string> insert(int idKey, string value) 
    {
        d[idKey] = value;
        vector<string> s;
        while(1)
        {
            if(d.find(current_id) == d.end())
                break;
            s.push_back(d[current_id++]);
        }
        return s;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */