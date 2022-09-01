class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) 
    {
        sentence += " ";
        int end_ind = sentence.find(" "), cnt = 1, start_ind = 0;
        while(end_ind != string::npos)
        {
            if(sentence.substr(start_ind, end_ind - start_ind).find(searchWord) == 0)
                return cnt;
            cnt++;
            start_ind = end_ind + 1;
            end_ind = sentence.find(" ", start_ind);
        }
        return -1;
    }
};