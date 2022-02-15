class Bitset {
public:
    vector<bool>bits;
    int cnt;
    bool isFlip;
    Bitset(int size) {
        bits.resize(size,false);
        cnt=0;
        isFlip=false;
    }
    void fix(int idx) {
        if((bits[idx] + isFlip)%2==0){
            cnt++;
            bits[idx]=!bits[idx];  
        }
    }
    void unfix(int idx) {
      if((bits[idx] + isFlip)%2!=0){
            cnt--;
            bits[idx]=!bits[idx];  
        } 
    }
    void flip() {
        cnt=bits.size()-cnt;
        isFlip=!isFlip;
    }
    bool all() {
       return cnt==bits.size(); 
    }
    bool one() {
        return cnt>=1;
    }
    int count() {
       return cnt; 
    }
    string toString() {
        string ans;
        for(auto bit:bits)
            ans.push_back((bit+isFlip)%2?'1':'0')  ;   
        return ans;
    }
};