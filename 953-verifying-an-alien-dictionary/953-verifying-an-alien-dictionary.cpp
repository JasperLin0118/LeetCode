class Solution {
public:
    bool cmp(string a, string b, vector<int> letters)
    {
        int i=0, j=0;
        while(i < a.length() && j < b.length())
        {
            if(a[i] == b[j])
            {
                i++;
                j++;
            }
            else
                return (letters[a[i] - 'a'] < letters[b[j] - 'a']);
        }
        return i == a.length();
    }
    bool isAlienSorted(vector<string>& words, string order) 
    {
        vector<int> letters(26);
        for(int i=0;i<26;i++)
            letters[order[i] - 'a'] = i;
        for(int i=0;i<words.size()-1;i++)
        {
            if(words[i] != words[i+1])
            {
                if(!cmp(words[i], words[i+1], letters))
                    return false;
            }
        }
        return true;
    }
};