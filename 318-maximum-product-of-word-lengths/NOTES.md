```
int n = v.size();
bitset<26> arr[n+1];
for(int i=0;i<n;i++){
for(int j=0;j<v[i].length();j++){
arr[i] |= 1<<(v[i][j]-'a');
}
}
int maxi = 0;
for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
if((arr[i] & arr[j])==0)
maxi=max(maxi,(int)v[i].length()*(int)v[j].length());
}
}
return maxi;
```