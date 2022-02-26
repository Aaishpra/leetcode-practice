class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        
       int n=plants.size();
        int alice=0,bob=n-1,temp1=capacityA,temp2=capacityB;
        int count=0;
        
        while(alice<bob){
            if(temp1<plants[alice]){
                count++;
                temp1=capacityA-plants[alice]; // refill Alice, and move forward after watering this.
            }else{
                temp1-=plants[alice];
            }
            if(temp2<plants[bob]){
                count++;
                temp2=capacityB-plants[bob]; // refill Bob, and move forward after watering this.
            }else{
                temp2-=plants[bob];
            }
            alice++,bob--;
        }
        
        if(alice==bob){
            if(max(temp1,temp2)<plants[alice]) // only in case of odd elements, both alice and bob hit same element.
                count++;
        }
        return count;
    }
};