class Solution {
public:
    int numSquaresUtil(int n){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        int ans=INT_MAX;
        int i=1;
        int end=sqrt(n);
        while(i<=end){
            int perfect_square=i*i;
            int no_of_perfect_squares=1+numSquaresUtil(n-perfect_square);
            ans=min(ans,no_of_perfect_squares);
            ++i;
        }
        return ans;
    }
    int numSquares(int n) {
        return numSquaresUtil(n)-1;
    }
};