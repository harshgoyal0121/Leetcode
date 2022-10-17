class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int min_profit=INT_MAX;
        
        for(int i=0; i<prices.size(); i++){
            min_profit = min(min_profit, prices[i]);
            ans = max(ans, prices[i]-min_profit);
        }
        return ans;        
    }
};
