class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i = 0; i < prices.size(); i++){
            for(int j = i + 1; j < prices.size(); j++){
                if(prices[i] <= prices[j]){

                    res = max(res,prices[j] - prices[i]);
                }
                
            }
        }
        return res;
    }
};
