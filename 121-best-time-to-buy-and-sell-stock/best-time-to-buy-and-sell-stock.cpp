class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int intital_price=prices[0];
        int max_profit=0;
        for(int i=0;i<prices.size();i++){
            if(intital_price>prices[i]){
                intital_price=prices[i];
            }
            max_profit=max(max_profit, prices[i]-intital_price);
        }
        return max_profit;
    }
};