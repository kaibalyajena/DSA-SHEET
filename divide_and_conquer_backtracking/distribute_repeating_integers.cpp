class Solution {
public:
    bool canDistributeUtil(vector<int>& count,vector<int>&quantity,int curr_customer){
        //all customers are satisfied 
        //base case
        if(curr_customer==quantity.size()){
            return true;
        }
        //check if any item in the count array is present in enough quantity to satisfy the quantity needs of the current customer
        for(int i=0;i<count.size();i++){
            if(count[i]>=quantity[curr_customer]){
                //assign that quantitiy to the current customer
                count[i]-=quantity[curr_customer];
                //if all other customers all also satisfied then return true
                if(canDistributeUtil(count,quantity,curr_customer+1)){
                    return true;
                }
                //if all customers are not satisfied then backtrack and deallocate the quantity of the curr customer
                count[i]+=quantity[curr_customer];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        //store number and its count in the unordered map
        unordered_map<int,int> countMap;
        for(auto i:nums){
            countMap[i]++;
        }
        //make a count vector containing the frequencies
        vector<int> count;
        for(auto it:countMap){
            count.push_back(it.second);
        }
        //optimization (sort in decreasing order)
        //we will reach the false conditions quickly if we start satisfying the higher quantity first
        sort(quantity.rbegin(),quantity.rend());
        return canDistributeUtil(count,quantity,0);
    }
};