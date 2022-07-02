#define mod 1000000007
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& wc) {
      
        sort(hc.begin(),hc.end());
        sort(wc.begin(),wc.end());
        int n1=hc.size(), n2=wc.size();
        vector<int> height;
        vector<int> width;
        height.push_back(abs(h-hc[n1-1]));
        height.push_back(abs(hc[0]));
        
        width.push_back(abs(w-wc[n2-1]));
        width.push_back(abs(wc[0]));
        
        for(int i=1;i<n1;i++){
            height.push_back(abs(hc[i-1]-hc[i]));
        }
         for(int i=1;i<n2;i++){
            width.push_back(abs(wc[i-1]-wc[i]));
        }
        long long int mh = *max_element(height.begin(), height.end());
        long long int mw = *max_element(width.begin(), width.end());
        
        
        return (int)(mh%mod*mw%mod);
    }
};