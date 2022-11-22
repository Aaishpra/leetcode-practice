class Solution {
public:
   
    int numSquares(int n) {
        //Legendre's 3 square theorem 
        //All numbers can be represented as sum of 3 numbers 1,2,3 and only number in the form of 4^a(8b+7) is sum of 4 perfect squares
        if(ceil(sqrt(n))==floor(sqrt(n))) return 1; // already Perfect square return 1;
        while(n%4==0){
            n=n/4;
        }
        if(n%8==7){
            return 4; //In the form of 4^a(8b+7) then return 4;
        }
        for(int i=1;i*i<=n;i++){
            int base= sqrt(n-i*i);
            if(base*base==n-i*i) //if perfect square then return 2; 
                return 2;
        }
        return 3; //all cases failed then return 3
    }
};