class Solution {
public:
    bool isPowerOfFour(int num) {
      return num>0 && !(num&(num-1)) && !((int)log2(num)&1);
}};