class Solution {
public:
    string entityParser(string text) 
    {
        int start = text.find("&"), curr_end = 0;
        while(start != string::npos)
        {
            curr_end = text.find(";", start + 1);
            string curr_substr = text.substr(start, curr_end - start + 1);
            if(curr_substr == "&quot;")
                text.replace(start, 6, "\"");
            else if(curr_substr == "&apos;")
                text.replace(start, 6, "\'");
            else if(curr_substr == "&amp;")
                text.replace(start, 5, "&");
            else if(curr_substr == "&gt;")
                text.replace(start, 4, ">");
            else if(curr_substr == "&lt;")
                text.replace(start, 4, "<");
            else if(curr_substr == "&frasl;")
                text.replace(start, 7, "/");
            start = text.find("&", start + 1);
        }
        return text;
    }
};