class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       int boats=0;
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        while(i<=j)
        {
            if(people[i]+people[j]<=limit) //bot can go together
            {
                i++;
                j--;
               
            } 
            else //heavier can go alone
                j--;
             boats++;
        }
        return boats;
        
    }
};