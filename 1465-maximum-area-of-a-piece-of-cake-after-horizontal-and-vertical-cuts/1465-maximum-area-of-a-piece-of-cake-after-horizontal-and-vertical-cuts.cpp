#define mod 1000000007
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& wc) {
      
        sort(hc.begin(),hc.end());
        sort(wc.begin(),wc.end());
        int n1=hc.size(), n2=wc.size();
        vector<int> height;
        vector<int> weight;
        height.push_back(abs(h-hc[n1-1]));
        height.push_back(abs(0-hc[0]));
        
        weight.push_back(abs(w-wc[n2-1]));
        weight.push_back(abs(0-wc[0]));
        
        for(int i=1;i<n1;i++){
            height.push_back(abs(hc[i-1]-hc[i]));
        }
         for(int i=1;i<n2;i++){
            weight.push_back(abs(wc[i-1]-wc[i]));
        }
        long long int a = *max_element(height.begin(), height.end());
        long long int b = *max_element(weight.begin(), weight.end());
        
        // Multiply and return
        return (int)(a%mod*b%mod);
    }
};