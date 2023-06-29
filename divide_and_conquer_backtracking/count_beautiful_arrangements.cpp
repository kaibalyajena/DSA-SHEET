class Solution {
public:
    void countArrangementUtil(vector<int>& arr,int &count,int n,int curr_num){
        if(curr_num==n+1){
            count++;
            return;
        }  
        for(int i=1;i<=n;i++){
            //put the curr_num in a place in the array if the space is space is empty and either index modulo curr num is zero or vica versa
            if(arr[i]==0 && (curr_num%i==0 || i%curr_num==0)){
                arr[i]=curr_num;
                countArrangementUtil(arr,count,n,curr_num+1);
                arr[i]=0;
            }
        }
    }
    int countArrangement(int n) {
        int count=0;
        vector<int> arr(n+1);
        countArrangementUtil(arr,count,n,1);
        return count;
    }