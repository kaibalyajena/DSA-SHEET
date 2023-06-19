class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        //base conditions
        //target sum reached and no more dice rolls remaining (means found a valid ans)
        if(n==0&&target==0){
            return 1;
        }
        //no more dice rolls left and target has not been reached (not a valid ans)
        if(n==0&&target!=0){
            return 0;
        }
        //target reached/exceeded but still some turns remaining (not a valid ans)
        if(target<=0&&n>0){
            return 0;
        }
        int ans=0;
        //try all possible values of the dice (k values for each dice) and reduce no of dice rolls by 1 each time and subtract the face up value of dice from the target and then add to the ans variable if valid answers are present.
        for(int i=1;i<=k;i++){
            ans+=numRollsToTarget(n-1,k,target-i);
        }
        return ans;
    }
};