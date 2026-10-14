class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minN = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            if(minN > prices[i]) minN = prices[i];

            res = max(res,prices[i] - minN);
        }
        return res;
    }
};
