class Solution {
public:
    //used gap method which is like shell sort
    void merge(vector<int>&nums, int s , int mid, int e){
        int len=e-s+1;
        int gap=len/2 + len%2;
        while(gap>0){
            int i=s,j=i+gap;
            while(j<=e){
                if(nums[i]>nums[j]){
                    swap(nums[i],nums[j]);
                }
                ++i;
                ++j;
            }
            if(gap==1){
                break;
            }
            gap=gap/2 + gap%2;
        }
    }
    void mergeSort(vector<int>&nums,int s,int e){
        if(s>=e){
            return;
        }
        int mid=(s+e)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,mid,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};