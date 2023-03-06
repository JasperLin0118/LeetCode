class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) 
    {
        int total = 0;
        vector<int> prefix_sum(arr.size());
        prefix_sum[0] = arr[0];
        for(int i=1;i<arr.size();i++)
            prefix_sum[i] = prefix_sum[i-1] + arr[i];
        for(int i=0;i<arr.size();i+=2)
        {
            cout << prefix_sum[i] << endl;
            total += prefix_sum[i];
            int curr = prefix_sum[i];
            for(int j=i+1, cnt=0;j<arr.size();j++)
            {
                total += curr + arr[j] - arr[cnt];
                curr += arr[j] - arr[cnt];
                cnt++;
            }
        }
        return total;
    }
};