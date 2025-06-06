class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price=prices[0];
        int maxprofit=0;
        for(int i=0;i<prices.size();i++){
            if(price>prices[i]){
                price=prices[i];
            }
            maxprofit=max(maxprofit, prices[i]-price);
        }
        return maxprofit;
    }
};