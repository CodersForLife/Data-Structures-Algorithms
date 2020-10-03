int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || n == 1)
            return 0;
        int mini = prices[0];
        int ans = 0;
        for(int i = 1;i<n;i++)
        {
            ans = max(ans, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return ans;
    }