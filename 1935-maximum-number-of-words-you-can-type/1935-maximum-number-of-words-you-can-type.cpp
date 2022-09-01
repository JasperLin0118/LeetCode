class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) 
    {
        text += " ";
        int ans = 0, start = 0, end = text.find(" ");
        while(end != string::npos)
        {
            bool flag = true;
            for(char c: brokenLetters)
            {
                if(text.substr(start, end - start).find(c) != string::npos)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans++;
            start = end + 1;
            end = text.find(" ", start);
        }
        return ans;
    }
};