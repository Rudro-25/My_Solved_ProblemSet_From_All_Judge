class Solution {
public:
    string getSmallestString(int n, int k) {
        k-=n;
        string ans;
        for(int i=0;i<n;i++) ans+='a';
        for(int i=n-1;i>=0;i--){
            ll baki= min(25,k);
            ans[i]+=baki;
            k-=baki;
        }
        return ans;
    }
};
