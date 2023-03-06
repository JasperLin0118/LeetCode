class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) 
    {
        int mx = releaseTimes[0];
        char c = keysPressed[0];
        for(int i=1;i<releaseTimes.size();i++)
        {
            cout << releaseTimes[i] - releaseTimes[i-1] << " ";
            if(releaseTimes[i] - releaseTimes[i-1] > mx)
            {
                mx = releaseTimes[i] - releaseTimes[i-1];
                c = keysPressed[i];
            }
            else if(releaseTimes[i] - releaseTimes[i-1] == mx && keysPressed[i] > c)
                c = keysPressed[i];
        }
        return c;
    }
};