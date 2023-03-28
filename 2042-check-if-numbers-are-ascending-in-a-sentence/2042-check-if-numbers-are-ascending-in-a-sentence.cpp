class Solution {
public:
    bool areNumbersAscending(string s) 
    {
        bool ascending = true;
        vector<int> nums;
        const char* delim = " ";
        char* converted_s = strdup(s.c_str());
        char* t = strtok(converted_s, delim);
        while(t != NULL)
        {
            try
            {
                nums.push_back(stoi(t));
            }
            catch(invalid_argument const& ex)
            {
                t = strtok(NULL, delim);
                continue;
            }
            t = strtok(NULL, delim);
        }
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] <= nums[i-1])
                ascending = false;
        }
        return ascending;
    }
};