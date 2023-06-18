class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        for(int i=0;i<prices.size();i++){
            for(int j=i;j<prices.size();j++){
                maxi=max(maxi,prices[j]-prices[i]);
            }
        }
        return maxi;
    }
};



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int buy=0;
        for(int i=0;i<prices.size();i++){
            if(prices[buy]>prices[i]){
                buy=i;
            }
            maxi=max(maxi,prices[i]-prices[buy]);
        }
        return maxi;
    }
};