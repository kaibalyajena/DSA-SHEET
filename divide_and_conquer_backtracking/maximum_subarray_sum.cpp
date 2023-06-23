class Solution {
public:
    //the subarray with maximum value can either lie in the left side of mid ,right side of the mid or across mid
    //so calculate these three and take the max.
    int maxSubArrayUtil(vector<int>&nums,int start,int end){
        if(start==end){
            return nums[start];
        }
        int mid=(start+end)/2;
        int left_sub_array=maxSubArrayUtil(nums,start,mid);
        int right_sub_array=maxSubArrayUtil(nums,mid+1,end);
        int max_left_border_sum=INT_MIN;
        int left_border_sum=0;
        for(int i=mid;i>=start;i--){
            left_border_sum+=nums[i];
            max_left_border_sum=max(max_left_border_sum,left_border_sum);
        }
        int max_right_border_sum=INT_MIN;
        int right_border_sum=0;
        for(int i=mid+1;i<=end;i++){
            right_border_sum+=nums[i];
            max_right_border_sum=max(max_right_border_sum,right_border_sum);
        }
        int cross_border_sum=max_left_border_sum+max_right_border_sum;
        return max(left_sub_array,max(right_sub_array,cross_border_sum));
    }
    int maxSubArray(vector<int>& nums) {
       return maxSubArrayUtil(nums,0,nums.size()-1);
    }
};