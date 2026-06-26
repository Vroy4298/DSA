class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy = prices[0];
        int maxProfit = 0;

        for(int i=1;i<prices.size();i++)
        {
            buy = min(buy, prices[i]);

            int currentProfit = prices[i] - buy;

            maxProfit = max(maxProfit,currentProfit);
        }

        return maxProfit;
    }
};