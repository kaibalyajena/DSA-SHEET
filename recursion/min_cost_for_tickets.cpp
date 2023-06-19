class Solution {
public:
    int mincostTicketsUtil(vector<int>& days,vector<int>& costs ,int i){
        //base case
        //we have taken tickets which cover all the days of the days array
        if(i>=days.size()){
            return 0;
        }
        //in case we take 1 day ticket
        //cost = cost of 1 day ticket + cost for all other day tickets
        int day1=costs[0]+mincostTicketsUtil(days,costs,i+1);
        //in case we take 7 day ticket
        //cost = cost of 7 day ticket + cost for all other days which are 6 days after the      current date
        int end_date=days[i]+7-1;
        int j=i;
        //eliminating all the covered days and skipping right to the day we again need a ticket for
        while(j<days.size() &&days[j]<=end_date){
            j++;
        }
        int day7=costs[1]+mincostTicketsUtil(days,costs,j);
        //in case we take 30 day ticket
        //cost = cost of 30 day ticket + cost for all other days which are 29 days after the      current date
        int end_date1=days[i]+30-1;
        int k=i;
        while( k<days.size()&&days[k]<=end_date1 ){
            k++;
        }
        int day30=costs[2]+mincostTicketsUtil(days,costs,k);
        //find the minimum of these costs
        return min(day1,min(day7,day30));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return mincostTicketsUtil(days,costs,0);
    }
};