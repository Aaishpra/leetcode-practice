class Solution {
public:
    int mirrorReflection(int p, int q) {
        while(p%2==0 and q%2==0){
            p=p/2;
            q=q/2;
        }
        if(p%2==1 and q%2==1) return 1;
        if(p%2==0 and q%2==1) return 2;
        if(p%2==1 and q%2==0) return 0;
        return -1;
    }
};