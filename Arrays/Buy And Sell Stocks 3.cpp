int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        if(n == 2) {
            return max((prices[1] - prices[0]), 0);
        }
        
        vector<int> secondMax(n,0);
        
        int maxPrice = prices[n-1];
        int maxProfit = 0;
        for(int i=n-2;i>=0;i--) {
            maxProfit = max(maxProfit, maxPrice - prices[i]);
            secondMax[i] = maxProfit;
            maxPrice = max(maxPrice, prices[i]);
        }
        
        int minPrice = prices[0];
        int ans = 0;
        for(int i=1;i<n;i++) {
            int currentProfit = prices[i] - minPrice;
            minPrice = min(minPrice, prices[i]);
            ans = max(ans,currentProfit);
            if(i != n-1) 
                ans = max(ans, currentProfit + secondMax[i+1]);
        }
        return ans;
    }