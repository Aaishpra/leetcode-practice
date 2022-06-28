class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
     char res=letters[0];
        int lo=0,hi=letters.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(letters[mid]<=target) lo=mid+1;
            else if(letters[mid]>target) {
                hi=mid-1;
                res=letters[mid];
            }
        }
        return res;
    }
};