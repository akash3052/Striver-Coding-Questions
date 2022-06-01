class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minprice=INT_MAX;
        int maxprofit=0;
        for(int i=0;i<prices.size();i++)
        {
            //updating minprices if elements having value less than minprice is found.Since we have to sell only one stock we are trying to buy stock at minm price and trying to sell at maxm price after the index(day) from where we have bought the stock.
            minprice=min(minprice,prices[i]);
            //We are assuming that we are selling the stock at price prices[i] . So profit will be prices[i]-minprice.
            maxprofit=max(maxprofit,prices[i]-minprice);
        }
        
        return maxprofit;
    }
};
