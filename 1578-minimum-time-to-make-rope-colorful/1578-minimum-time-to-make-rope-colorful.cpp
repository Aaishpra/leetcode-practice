class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int prev=0;
        int sum=0;
        for(int i=1;i<colors.size();i++){
            if(colors[prev]!=colors[i]){
              prev=i;
            }
            else {
                sum+=min(neededTime[prev],neededTime[i]);
                 if(neededTime[prev]<neededTime[i])
                    prev=i;
            }
           
        }
        return sum;
    }
};